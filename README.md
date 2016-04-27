# Collins_Amaya_Gerstle_CSCI2270_FinalProject
CSCI 2270 Final Project

Design a blackjack game simulator with the use of linked lists.

-Design each node (player) to have nine (maximum number of cards possible) 

-Maximum of 8 players

-----------------------------------------------------------------------------------------------------------

Project Summary:

  We are designing and implementing a blackjack game in which we are using linked lists. We are going to use the head as the player with approximately nine pointers pointing to nodes which will hold cards. We chose to use nine nodes because that is the maximum amount of cards possible, and since it would be more efficient to hold at least seven empty spots than to recursively call to create empty nodes then use them, we are using this technique. Nine is the max (AH, AC, AS, AD, 2H, 2C, 2S, 2D, 3H, 3C, 3S) which equals to (4(1) + 4(2) + 3(3)) = (4 + 8 + 9) = 21. Then we will have a random generator to shuffle the cards (we will have no dealer, just the computer dealing) and then if you bust, our program will tell the other players you busted. We will follow standard rules and we will try our best to implement a GUI, however since we haven't learned anything about GUIs we have no promises. 

-----------------------------------------------------------------------------------------------------------

How to Run:
*Setting up the program*
To set up the program in your complier you can either download all of the program files or copy and paste them into a new project.  Unlike common projects, our project uses two header files and two .cpp files.  Be careful in making sure that both are in the program project.  As far as choosing a compiler it is really up to you, program is designed around Codeblocks C++. 

*Playing the program*
When the program starts, the user is prompted with a main menu.  The menu gives the user the choice to either begin or quit the blackjack game.  Once the decision is made to start the game, the user must make 4 choices;  1)Choose the number of decks to play with, 2)Choose how many players will be in the game (max of 9), 3)Enter how much money each player will start with, & 4)The names of each of the players.

From there on, the user interface consists of command line prompts.  The program begins to deal and begins the game by giving each user a randomized pair of cards.  Then the user has the option to hit or stay.  The program is able to recognize the sum of the two cards in the user's hand.  The program is also able to tell if the amount the user bets is over the amount of allocated playing funds.  The program is also able to tell when the sum is a perfect blackjack and automatically awards the player.
  
-----------------------------------------------------------------------------------------------------------
  
Dependicies:

-----------------------------------------------------------------------------------------------------------

System Requirements:

-----------------------------------------------------------------------------------------------------------

Group Members:

  David Gerstle (https://github.com/gerstled)
  Raul Amaya (https://github.com/ramaya38)
  Oliver Collins (https://github.com/OliverCollins)
  
-----------------------------------------------------------------------------------------------------------

Open Issues/Bugs:

  
