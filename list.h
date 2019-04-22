  //Victor Ochia. CS202. Program #1 list.h. Purpose of this file is to display function
  //definitions within a hierchy of classes that iplement the structure of the program
  //purpose of assignment is to create an interactive go - fish game. 




   #include <cctype>
   #include <iostream>
   #include <fstream>
   #include <cstring>
   #include <stdio.h>
   #include <time.h>
   #include <stdlib.h>
    
   class Card  //the card class. Manages card information and functionality of a card 
   {

       public:
          Card(); //constructor 
          ~Card(); //destructor               
          Card(const Card & to_copy); //the copy constructor
          void assign_card(int i, int j); //gives a car a value
          void display(); //displays the card
          int retrieve_info(char *& suite); //retrieves information in the card
         
       protected:
          int card_number; //card number
          char * card_type; //hearts, spades, etc


   };
 

 
   class node: public Card //the node class. Manages the pointers to each card
   {

        public:
           node(); //the node constructor
           node(const node & to_copy); //the copy constructor
           node *& nex(); //the next pointer (gives access)
           node *& prev(); //the preivous pointer (gives access)
           void connect_node(node* suit [], int i, node *& temp); //connects a node to a data structure


        private:
           node * next; //next pointer
           node * previous; //previous pointer


   };



   class Deck //the deck class. this class is responsible for the stack of cards the user picks from
   {
            


         public:
            Deck(int size = 4); //the constructor. takes in four elements in the array 
            Deck(const Deck & to_copy); //the copy constructor     
            ~Deck(); //the destructor
            void create_deck(); //creates the deck 
            void display_deck(); //displays the deck
            void connect_node(node & equate, int i, node *& temp); //connects a node in the deck data structure
            void draw_card(char *& suit, int & j); //removes a card from the deck
            void shuffle(); //shuffles cards in the deck
       
         protected:
            node ** suit; //the array node pinters

    
         private:
            int array; //te array size
            node equate; //gives access to a node class
   };




   class Hand //the hand class. Managers a players hand
   {

       public:
          Hand(int size = 13); //the constructor. Takes in array size
          Hand(const Hand & to_copy); //the copy constructor
          ~Hand(); //the destructor
          void display(); //displays the hand
          void check_book(); //check if player has a book of cards
          bool empty_hand(); //check if player has a complete empty hand
         
       protected:
       //   Deck my_deck; //has aceess to the deck class for easy drawing
          int array; //array size
          node ** rank; //array of pointers
 
       private:
          Deck my_deck;
      
      
   };


  
  
 

   class General_player: public Hand //general player class. Manages functionalities that both players would have 
   {
       public:
          void draw_card(Deck & my_deck); //function draws a card from the deck
          int check_value(int i, char *& card_type); //function checks to see if other player has the value
          int get_value(char *& card_type, int value); //puts a new card into a players deck 




   };




   class Computer: public General_player //the computer player class
   {
 

       public:
          int inquired_value(); //asks a player if they have a value randomely
          
         

   };



   class Human: public General_player //the human player class
   {

       public: 
          int inquired_value(); //asks the computer if they have a value (entered in)

       

   };


