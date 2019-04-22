# Artificial-inteligence-Go-Fish


The artificial intelligence go fish is a c++ command line application made to simulate playing go fish with a computer.The game uses OOP 
and class hierarchy concepts to create an interactive go fish game.

for this assignment are arrays of doubly linked lists as well as a hash table. I believe that an array of doubly linked list is a 
good solution for this assignment because since we are using cards, we can sort out the cards, making each array represent a suite 
of cards. The doubly linked list makes it easier to shuffle the deck without the use of a previous pointer. I decided to use a hash 
table for the players hand because it allows easy retrieval by simply organizing the key value by the card number that the player has.

# Design Aspects

In terms of an object oriented design, I believe that my program has a good setup. All of the classes that I have set up 
have clear and different roles. I believe that my classes are doing their own jobs and I found it easy to push up commonalities 
between my classes, making some of them into a parent class, For example, there is a human player and a computer player in the go 
fish game. It was easy for me to make note of the commonalities between both of these players and successfully push that up into a 
general player class. In fact, the only difference between the two types of players is that one of them picks a number to ask for a
random, and the other actually decides what number to ask for instead. Another place a hierarchical relationship fit in  would be the 
relationship between the deck, hand, and suite classes. I felt like it was appropriate to derive the hand and suit from the deck class 
because both of these arrangements are coming from the deck. A players hand comes from the deck so it is not bad to have it derived from
the deck. A suite also comes from a deck in the beginning before it is shuffled, so it is also appropriate to have suite derived from
the deck. in order to have a display function. One aspect of my program that was not object oriented was the hand class only having
one child (which was the card class), as well as the card class only having one child (which was the general player class). 
I believe it would have been more beneficial to find a more even relationship between these classes that would have been more 
object oriented if I had more time to work on the design aspect. In a larger application, I believe this way of coding would be
harder to maintain.

