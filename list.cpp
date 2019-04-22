   //Victor Ochia. CS202. Program #1 list.cpp Purpose of this file is to implement functions
   //from the classes in the list.h file
   //purpose of assignment is to create an interactive go - fish game. 4/24/2015




   #include "list.h"

   using namespace std;

   Deck::Deck(int size) //Deck constructor. Takes in an array size
   {

       int i = 0; //  int goes through four loop and initializes indexes

       array = size; // set array variable in class equal to size

       suit = new node *[size]; // creates new aray of node pointers
       
       for(i; i < size; ++i) //for loop. initialzes array
       {
           suit[i] = NULL; 
       }

   }


 
   Deck::~Deck() //Deck Destructor
   {
      int i = 0; //goes throgh each index of the array of pointers to nodes.
      node * current; // goes through list 

      for(i; i < array; ++i) //for loop goes through indexes
      {
          if(suit[i]) // if index isnt null
          {
              current = suit[i];  //set current to beginning
              while(current) //while we are still in the loop
              {
                  current = current -> nex();
                  delete suit[i];
                  suit[i] = current;
                  
              }
           }

      }
   
      delete [] suit; //delete the array
      suit = NULL;
   }
 


   Hand::~Hand() //player hand destructor
   {
       int i = 0; //runs through for loop of indices
       node * current; //pointer goes through list
  
       for(i; i < array; ++i) //for loop that  goes throgh the indecise
       {
   
           if(rank[i]) //if index isnt null
           {
               current = rank[i]; //set current to beginning
               while(current) //while we are still in the loop
               {
                   current = current -> nex();
                   delete rank[i];
                   rank[i] = current;
               }
           }
       }
    
       delete [] rank; //delete the array
       rank = NULL; //set it to null
   }
 


    Deck::Deck(const Deck & to_copy) //deck copy constructor. Takes in acopy of the deck by reference
    {

        int i = 0; // goes through indecis of array                                       
        node * current; //pointer goes through the list                                   
                                                                                          
        node * copy_current; //pointer goes through list of what we are copying           
                                                                                          
        for(i; i < array; ++i) //for loop. goes through indeces                           
        {                                                                                 
    

            current = suit[i]; // current pointer initialized to beginning of list        
                                                                                          
                                                                                          
            while(copy_current) //while the list we are copying from is not null;         
            {
          
                if(!current) // if the list we are copying to is null                     
                {   
                    suit[i] = new node(*copy_current); //allocate new node and call the nodes copy constructor.
                    current = suit[i]; // current pointer initialized to beginning of list
                    copy_current = copy_current -> nex(); //traverse the pointer of the node we are copying from
          
                }                                                                         
          
                else                                                                      
                {                                                                         
                    current -> nex() = new node(*copy_current); //the nodes we are copying to              
                    current -> nex() -> prev() = current; //connect the previous pointer  
                    current = current -> nex(); //set cuurent pointer to next node        
                    copy_current = copy_current -> nex(); //traverse the pointer of the node we are copying from                                                                     
                }
     
                                
            }
        }

    }
        


    Hand::Hand(const Hand & to_copy) //the hand copy constructor. Takes in a copy of the hand by reference
    {

        int i = 0; // goes through indecis of array
        node * current; //pointer goes through the list
 
        node * copy_current; //pointer goes through list of what we are copying
       
        for(i; i < array; ++i) //for loop. goes through indeces
        {  
    

            current = rank[i]; // current pointer initialized to beginning of list
 
 
            while(copy_current) //while the list we are copying from is not null;
            {

                if(!current) // if the list we are copying to is null
                {   
                    rank[i] = new node(*copy_current); //allocate new node and call the nodes copy constructor.
                    current = rank[i]; // current pointer initialized to beginning of list
                    copy_current = copy_current -> nex(); //traverse the pointer of the node we are copying from

                }

                else
                {
                    current -> nex() = new node(*copy_current); //the nodes we are copying to              
                    current -> nex() -> prev() = current; //connect the previous pointer
                    current = current -> nex(); //set cuurent pointer to next node
                    copy_current = copy_current -> nex(); //traverse the pointer of the node we are copying from
                }

                                
            }
        }
                
    }
    
  

   node::node(const node & to_copy): Card(to_copy) //node copy constructor
   {
     
       next = NULL; //sets next and previous pointers to NULL;
       previous = NULL;

      // Card(to_copy); // calls the card copy constructor
    
         
   }

   Card::Card(const Card & to_copy) //card copy constructor
   {
       card_number = to_copy.card_number; //copy the card number 

       if(card_type) //if the card type isnt null
          delete [] card_type; //delete the card type

       card_type = new char[strlen(to_copy.card_type) + 1]; //set card_type to NULL
       strcpy(card_type, to_copy.card_type); //copy the card type


     
    }


 
   void Deck::shuffle() //function shuffles the deck
   {

       node * current1; // current pointer for the first list we swap
       node * current2; //current pointer for the second list we swap
       int i = 0; //goes through loop swapping random cards 52 times
       int j = 0; //the card number we are switching
       int ones_card_type = 0; //the first card number we are switching
       int twos_card_type = 0; //the second card number we are switching
       int index_value1 = 0; // the index where the first card we are switching lives
       int index_value2 = 0;// the index where the second card we are switching lives
       int switch_value1 = 0; //the number where we are stopping to switch
       int switch_value2 = 0; //the second number where we are stopping to switch
       char * plug2 = NULL; //the card suit name we are swapping 
       char * plug1 = NULL; //the second card suit name we are swapping
       int assign1 = 0; // the value we use to find out the suit name
       int assign2 = 0; //the second value we use to find out the suit name

       for(i; i < 52; ++ i) //for loop that switches random cards 52 times
       {

           index_value1 = rand() % 4; //randomly selects an index of array to go to
           index_value2 = rand() % 4;
           switch_value1 = rand() % 13; //randomly selects a number for the card we are switching
           switch_value2 = rand() % 13;


           if(suit[index_value1]) // if switch index is not null
           {
               current1 = suit[index_value1]; //set current to switch index
           
               
               while(current1 && j != switch_value1) // if we still have a list and we have not reached our switch value
               {
                   current1 = current1 -> nex(); // / traverse urrent
                                   
                   ++j; //add 1 to j
               }

                j = 0;

               assign2 = current1 -> retrieve_info(plug2); //get the info for the card we want to switch

               if(strcmp(plug2, "Club") == 0)  //find out what numberical value to assign the card                                                            
                   twos_card_type = 0;                                                                        
                                                 
               if(strcmp(plug2, "Diamond") == 0)  
                  twos_card_type = 1;   
                                                                                          
                                                                                          
               if(strcmp(plug2, "Heart") == 0)                            
                  twos_card_type = 2;                                                                          
                                                                                          
               if(strcmp(plug2, "Spade") == 0)
                  twos_card_type = 3;               


            }        
           
           if(suit[index_value2])// takes in an index array where we are swapping card
           {
               current2 = suit[index_value2]; //set second current pointer to this suit index

               while(current2 && j != switch_value2) // while we are in the list and we have not reached our switch value
               {
                   current2 = current2 -> nex();
                   ++j;
               }

               j = 0;
               assign1 = current2 -> retrieve_info(plug1); //retrieve information from the card we wish to switch 
     
               if(strcmp(plug1, "Club") == 0)  //find out what numberical value to assign the card
                 ones_card_type = 0;

               if(strcmp(plug1, "Diamond") == 0)     
                  ones_card_type = 1;

               if(strcmp(plug1, "Heart") == 0)    
                  ones_card_type = 2;

               if(strcmp(plug1, "Spade") == 0)     
                  ones_card_type = 3;
      
      

      
           }

           current1 -> assign_card(assign1, ones_card_type); //function here swaps each card
           current2 -> assign_card(assign2, twos_card_type);
          
           if(plug1) //delete tbe characters to free memory
           {
               delete [] plug1;
               plug1 = NULL;
           }

           if(plug2)
           {
               delete [] plug2;
               plug2 = NULL; 
           }

      }

   }



   void Hand::check_book() //function checks to see if we have all four cards
   {
       int i = 0; // goes through for loop
       int j = 0; //j is used to check if player has a book of cards
       node * current;
 
       for(i; i < array; ++i) //check for all the ranks if they have a book of cards
       {
          if(rank[i])
          {
              current = rank[i]; //set current pointer to beginning of list

              while(current) //while current is not null
              {
                  current = current -> nex(); //traverse
                  ++j; //add one to j
              }
              
              if(j == 4) //if we have a book of cards
              {
                  current = rank[i]; //set current to beginning of list

                  while(current) //delete the list
                  {
                      current = current -> nex();
                      delete rank[i];
                      rank[i] = current;
                  }
                
                  cout << "Current Player now has a book of " << i + 1  << "'s. A player wins once you have an empty hand.\n\n"; 

              }

              j = 0; //set j to zero
          }

       }

   }
      

   bool Hand::empty_hand() //function checks if player has an empty hand. returns a bool
   {
       int i = 0; //i goes through the array of ranks of the player

       for(i; i < array; ++ i) //for loop goes through the array of ranks of the player
       {
           if(rank[i]) //if we arent null
              return false;
       }
       
 
       return true;     //else return true

   }



 
   int Computer::inquired_value() //function randomly generates a value to ask the player if they have 
   {
       int inquired_value = 0; // //set value returned to zero initially

       inquired_value = rand() % array; //picks a random value in the bounds of the array

       if(inquired_value == 0) //if the value picked is zero, it automatically becomes six because no zero cards are allowed
       {
           inquired_value = 6;

       }
       return inquired_value; //return the random value
        
   }



   int Human::inquired_value() //function prompts player to pick a value 1 -13. returns that value
   {

       int inquired_value = 0; //initialze value
       do
       {
           cout << "\n\nEnter a number 1-13 that you would like to ask the computer if they have\n\n";
           cin >> inquired_value;
           cin.ignore(100, '\n');



        }while(inquired_value > 13 || inquired_value < 1); //do this while user does not ebter value 1 -13

 
        return inquired_value; //return the value


   }



 
   int General_player::check_value(int i, char *& card_type) //function checks the value given and takes it from the player. takes integer and a card_type as reference
   //returns a success or fail flag

   {
       node * current; //current pointer for traversal
       node * head; //head pointer
       i = i-1; //set i -1 to fit the array size
        
 

       if(!rank[i]) //if the user has none of these cards
          return 0;


       else 
       {
           current = rank[i]; //set crrent to beginning of list
         
        
           current -> retrieve_info(card_type); //retrieve the card info

           current = current -> nex(); //delete the card
           delete rank[i];
           rank[i] = current;
           return 1;
         
        }


   }


   int General_player::get_value(char *& card_type, int value) //gets a value (card) by adding it to a players hand. takes 
   //in a card type by reference along with an integer value
   {

       node * temp = new node; //create a new card
     

       int c = 0; //int determines the card suit

       if(strcmp(card_type, "Club") == 0)  //set c's value depending on the card_type                                          
          c = 0;                                                                          
                                                                                          
       if(strcmp(card_type, "Diamond") == 0)  
          c = 1;
      
  
       if(strcmp(card_type, "Heart") == 0)  
          c = 2;
           
        if(strcmp(card_type, "Spade") == 0)   
           c = 3;                    

  
       temp -> assign_card(value, c); //assigns card based on c's value and the value passed in 
       temp -> connect_node(rank, value-1, temp); //connects the card in the array
       
       
    }
   


 
   void Hand::display() //function displays a players hand
   {
       int i = 0; // int goes through array
       node * current; //current pointer

       for(i; i < array; ++i) //for loop goes through array displaying its contents
       {
           if(rank[i]) //if array index is not null
           {
               current = rank[i]; // set current to beginning of the list

               while(current) //while we are in the list
               {
                   current -> display(); //display
                   current = current -> nex(); // traverse
               }

            }
       }

   }



   Hand::Hand(int size)   //hand constructor. Takes in integer(13 by default)
   {
       int i = 0; //goes through array setting each index to null
      
       array = size; //set array equal to the size of the array

       rank = new node* [size]; //allocate new array

       for(i; i < array; ++i) //goes through array setting each index to null
       {
           rank[i] = NULL;
       }

   } 
   
  
   void General_player::draw_card(Deck & my_deck) //function aids player in drawing a card from the deck. Takes the deck class by reference
   {

       char * suit = NULL; //drawn card's suit is set to null
       node * temp; //temporary pointer to a card
       node * holder; //temporary pointer
       int j = 0; //the card number to be assigned       
       int c = 0; //determines the suit number based on what is drawn from the deck

       my_deck.draw_card(suit, j); //draws the card from the deck

       if(suit) //if suit is not null assign a value to c based on the suit of the card drawn from the deck
       {  
           if(strcmp(suit, "Club") == 0)
             c = 0;

           if(strcmp(suit, "Diamond") == 0)
              c = 1;

           if(strcmp(suit, "Heart") == 0)
              c = 2;

           if(strcmp(suit, "Spade") == 0)
              c = 3;
        
        
           delete [] suit; //delete suit memory to avoid memory leaks
           suit = NULL;

        }
       


       temp = new node; //create a new card
       temp -> assign_card(j, c);   //assign the card the values of the drawn card
       temp -> connect_node(rank, j-1, temp); //connect to user hand
     

   }   



   Card::~Card() //card class destructor
   {
       card_number = 0; // set the card number to zero
       
       if(card_type) //if card_type is not null
       {
           delete [] card_type; //delete the card type and set it to null
           card_type = NULL;
       }
   }



   void Deck::draw_card(char *& suite, int & j) //function draws card from the deck. Takes in a suit name and an integer by reference
   {
       int i = 0; //i goes through array untill we find the first card on the stack

       node * current; //current pointer traverses through list

       for(i; i < array; ++i) //i goes through array untill we find the first card on the stack
       {
           if(suit[i]) //if index is not null
           {
               current = suit[i]; //set current to beginning

             
               j = current -> retrieve_info(suite); //retrieve card information
              
               if(current -> nex()) //if we are still in list
               { 
                   current = current -> nex();
                   delete current -> prev();
                   suit[i] = current;
                   i = array;
               }
               else  //if we only have one node in the index
               {
                   delete current;
                   current = NULL;
                   suit[i] = NULL;
                   i = array;
               }
               
                     
           }        

       }
   }




   int Card::retrieve_info(char *& suite) //function retrieves card information. takes in a suit.
   {
      if(suite) //if suit is not null delete it to avoid memory leaks
        delete [] suite;
       
       
           suite = new char[strlen(card_type) + 1]; //allocate new memory for the suit
           strcpy(suite, card_type); //copy in the card_type
    

       return card_number; //return the card number

   }



   node *& node::nex() //function returns the next pointer in a node
   {
       return next;

   }



   node *& node::prev() //function returns the previous pointer in a node
   {
       return previous;

   }



   void Card::display() //function displays a card
   {
       cout << "Card Rank: "; 
      
       if(card_number == 1 || card_number > 10) //these card ranks have special names so they are displayed as such
       {
           if(card_number == 1)
              cout << "Ace\n";

           if(card_number == 11)
              cout << "Jack\n";

           if(card_number == 12)
              cout << "Queen\n";
       
           if(card_number == 13)
              cout << "King\n";
        }
        
        else //display the card number
           cout << card_number << endl;


       cout << "Card Suit: " << card_type << endl << endl; //diplay suit

   }



   void Deck::display_deck() //function displays the deck of cards
   {
       int i = 0; //goes through each array index
       node * current; //current pointer

       for(i; i < array; ++ i) //goes through array index displaying the cards
       {
           current = suit[i];
          
           while(current) //while we are in the list, diplay the cards
           { 
               current -> display();
               current = current -> nex();
           }    
           
       }
  
   
   }


   void Deck::connect_node(node & equate, int i, node *& temp) //function connects the nodes. takes in an int for the array index, a temp pointer to a node,
   //and a node class by reference
   {

       temp -> connect_node(suit, i, temp); //calls the connect node function in the card


   }



   Card::Card() //card constructor
   {
       int card_number = 0; //sets vsriables to null
       card_type = NULL;
   }



   void Card::assign_card(int j, int i) //fucntion assigns card a value. takes in an int j for a card number, and an int i for a card type
   {
       card_number = j; // the card number gets assigned the value j
   


       if(i == 0) //assigns the card type based on index number
       {
           if(!card_type) //if card is null
           {
              card_type = new char[strlen("club") + 1]; //assign a card type to the card
              strcpy(card_type, "Club");

           }

           else
           {  
              delete [] card_type; //if not null delete the card set it to null and assign a card type to the card
              card_type = NULL;
              card_type = new char[strlen("club") + 1];
              strcpy(card_type, "Club");
          
           }
       }

       if(i == 1) //assigns the card type based on index number
       {
           if(!card_type) //if card is null
           {   
               card_type = new char[strlen("Diamond") + 1]; //assign a card type to the card
               strcpy(card_type, "Diamond");
           }   

           else
           {
               delete [] card_type; //if not null delete the card set it to null and assign a card type to the card
               card_type = NULL;
               card_type = new char[strlen("Diamond") + 1];
               strcpy(card_type, "Diamond");
           }

       }

       if(i == 2) //assigns the card type based on index number
       {
           if(!card_type) //if card is null
           {
            card_type = new char[strlen("heart") + 1]; //assign a card type to the card 
            strcpy(card_type, "Heart");        
           }      

           else
           {
              delete [] card_type; //if not null delete the card set it to null and assign a card type to the card
              card_type = NULL;
              card_type = new char[strlen("heart") + 1];
              strcpy(card_type, "Heart");
           }

       }



       if(i == 3) //assigns the card type based on index number
       {
           if(!card_type) //if card is null
           {
              card_type = new char[strlen("spade") + 1]; //assign a card type to the card 
              strcpy(card_type, "Spade");
            }
            else
            {
               
              delete [] card_type; //if not null delete the card set it to null and assign a card type to the card
              card_type = NULL;
              card_type = new char[strlen("spade") + 1];
              strcpy(card_type, "Spade");
            }


       }

   }


   
   void Deck::create_deck() //function creates a deck of cards
   {
       int i = 0; //i goes throgh the array
       int j = 13; //j assigns the cards 1-13


       for(i; i < array; ++ i) //loop goes throgh the array
       {
           for(j; j > 0; --j) //loop assigns the cards 1-13
           {
               node * temp = new node;
               temp -> assign_card(j, i);
               
               connect_node(equate, i, temp);             
 
           }
           j = 13; //we set j back to 13 at the end

       }

   }   



   void node::connect_node(node* suit[], int i, node *& temp) //function connects nodes to data structure. takes in an array of pointers, an index integr
   //and a temporay pointer by reference
   {

       node * holder; // temporary pointer

       if(!suit[i]) //if index is null
          suit[i] = temp; //set passed in pointer to the index
             
       else //if index is not null
       {
          holder = suit[i]; //add the node at the beginnng of the index
          suit[i] = temp;
          temp -> next = holder;
          temp -> next -> previous = temp;
       }

   }
   

      
   node::node() //node constructor
   {
       next = NULL; //sets next and previous pointers to null
       previous = NULL;

   } 

      

