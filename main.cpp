   //Victor Ochia. CS202, Program # 1 main.cpp purpose of this file is to test out the program created in a client interface
   //purpose of assignment is to create an interactive go - fish game. 





   #include "list.h"
   using namespace std;

   
  
   void menu(); //function displays menu

   int main()
   {


       srand(time(NULL)); //makes the random generated values different each time thr program is run

       Deck my_deck; //the deck class object
       Human my_human; //the human class object    
       Computer my_computer; // computer class object 
       char answer;
       int k = 0; //keeps track of menu options
       int inquired_number = 0; //number which we want to check if other player has
       int j = 0; //keeps track of how many cards user gets from other player
       char * card_type = NULL;
       int i = 0; //for loop that initialzes each player with 7 cards
       int l = 0; //keeps track of alternating turns between player and computer
       int w = 0; //winners flag. Controls when the game ends


       my_deck.create_deck(); //creates the deck


       cout << "\n\nWelcome to the game of go-fish. The purpose of this game is to gather as many book of cards as possible\n";
       cout << "You will be guessing what is in the computers hand and the computer will guess whats in yours\n";
       cout << "(For testing purposes, your hand and the computers are available for viewing. Once you get a book of cards, they are removed from\n";
       cout << "your hand. players start off with 7 cards each. The first player to have an empty hand wins the game.\n\n";


       cout << "Starting game... Would you like to see the deck organized by suit before it is shuffled?(type: Y or N)\n\n";
       cin >> answer;
       cin.ignore(100, '\n');
       answer = toupper(answer);
       
       if(answer == 'Y') //if user wants to see deck before it is shuffled
       {
           cout << "\n\nBelow is the deck before it is shuffled";
           my_deck.display_deck();
       }

      
       cout << "\n\n**DECK HAS BEEN SHUFFLED**\n\n";
 

       my_deck.shuffle(); //shuffle the deck


    
       for(i; i < 7; ++i) //initializes each player with 7 cards
       {
          my_human.draw_card(my_deck);
          my_computer.draw_card(my_deck);

       }

       cout << "\n\n**initial cards have been given. Each player (You and the computer) start off with 7 cards**\n\n";

       i = 0;

      
       do
       { 
           menu(); //display menu

           cin >> k;
           cin.ignore(100, '\n');

           if(k ==1) //display deck
           {
               cout << "\n\n***Below is the deck***\n\n";

               my_deck.display_deck();
           
           }
              
       
           if(k == 2) //displays humans hand
           {
               if(my_human.empty_hand())
               cout << "\n\nYour hand is empty.\n\n";

               else
               {
                   cout << "\n\n**Below is your hand**\n\n";
                   my_human.display();
               }
           }
       

           if(k == 3) //displays computers hand
           {
               if(my_computer.empty_hand()) 
               cout << "\n\nComputers hand is empty\n\n";

               else
               {
                   cout << "\n\n**Below is the computers hand**\n\n";
                   my_computer.display();
       
               }

 
           }


           if(k == 4) //continue game
           {
               i = 0;

               if(l == 0) //humans turn
               {
                   do
                   {
                       inquired_number = my_human.inquired_value(); //ask for value

      
                       if(my_computer.check_value(inquired_number, card_type)) //check if other player has value
                       {
                           i = 1;
                           my_human.get_value(card_type, inquired_number); //get the value
                           ++j;
                 
                           while(my_computer.check_value(inquired_number, card_type)) //while player still has the desired value
                           {
      
                               my_human.get_value(card_type, inquired_number); //take the value
                               ++j; 
                           }

                           cout << "\n\nComputer: Yes, I have " << j << " " << inquired_number << "'s." << "I will now give them to you.\n\n";
                           j = 0;
                          
                           my_human.check_book(); //check to see if theres a book of cars
                       
                        }

                       else //else if no value intitially cout message
                       {           
                           i = 0;
                           j = 0;
                           cout << "\n\nComputer: I do not have any " << inquired_number << "'s. Go fish\n\n";                       
                           my_human.draw_card(my_deck); //if computer doesnt have value go fish in the deck                           
                           cout << "\n\ndisplay your new deck after fishing?(type Y or N)\n\n";
                           cin >> answer;
                           cin.ignore(100, '\n');
                           answer = toupper(answer);
          
                           if(answer == 'Y') //display deck?
                           {
                               my_human.display();
                           
                           }


                       }  

                   
 
                       my_human.check_book(); //check if there are any book values

                       if(my_human.empty_hand()) //if human has empty hand
                       {
                           cout << "\n\nComputer: Congratualations. You win. Game over.\n\n";
                           w = 1; //set win flag
                           i = 0;
                       }
                  
                       l = 1;

                  }while(i == 1);


               }
                  if(l == 1 && w == 0) //if no one has won and it is the other players turn
                  {

                       do //**Operations here are same as above, except it is the comuters turn to perform these operations with its hand**
                       {
                           inquired_number = my_computer.inquired_value();


                           if(my_human.check_value(inquired_number, card_type))
                           {
                               i = 1;
                               my_computer.get_value(card_type, inquired_number);

                               ++j;

                               while(my_human.check_value(inquired_number, card_type))
                               {

                                   my_computer.get_value(card_type, inquired_number);
                                   ++j;
                               }

                               cout << "\n\nComputer: Seems like you have " << j << " " << inquired_number << "'s." << "I will be taking those.\n\n";

                               cout << "computer";

                               my_computer.check_book();
                               j = 0;
                            }

                           else
                           {
                               i = 0;
                               j = 0;
                               cout << "\n\nComputer: So you dont have any " << inquired_number << "'s? I will go fish now.\n\n";

                               my_computer.draw_card(my_deck);
                               cout << "\n\ndisplay computers new deck after fishing?(type Y or N)\n\n";
                               cin >> answer;
                               cin.ignore(100, '\n');
                               answer = toupper(answer);

                               if(answer == 'Y')
                               {
                                   my_computer.display();

                               }



                       

                           }

                       
                      
                           my_computer.check_book(); //check to see if current player has book of cards

                           if(my_computer.empty_hand())  //if player now has an empty hand
                           {
                               cout << "\n\nComputer: You lose. I win. Game over.\n\n";
                               w = 1;
                           }

                       l = 0;

                       }while(i == 1);
                  }
           }


           if(k == 5) //user just wants to quit the game before it is over
           { 
       
               cout << "\n\nGAME TERMINATED\n\n";
               w = 1;
           }
              
              }while(w == 0);//contrls when game ends



     







       return 0;
   } 




   void menu()  //function displays menu
   {
       cout << "\n\nMenu options. Enter a number corresponding with the choices:\n\n";
       cout << "1. Display the deck             2. Display my hand\n\n";
       cout << "3. Display computers hand       4. resume game\n\n";
       cout << "5. Game over.\n\n";
   }








