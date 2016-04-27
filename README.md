# Collins_Amaya_Gerstle_CSCI2270_FinalProject
CSCI 2270 Final Project

Design a blackjack game simulator with the use of linked lists.

-Design each node (player) to have nine (maximum number of cards possible) 

-Maximum of 8 players


Project Summary:

  We are designing and implementing a blackjack game in which we are using linked lists. We are going to use the head as the player with approximately nine pointers pointing to nodes which will hold cards. We chose to use nine nodes because that is the maximum amount of cards possible, and since it would be more efficient to hold at least seven empty spots than to recursively call to create empty nodes then use them, we are using this technique. Nine is the max (AH, AC, AS, AD, 2H, 2C, 2S, 2D, 3H, 3C, 3S) which equals to (4(1) + 4(2) + 3(3)) = (4 + 8 + 9) = 21. Then we will have a random generator to shuffle the cards (we will have no dealer, just the computer dealing) and then if you bust, our program will tell the other players you busted. We will follow standard rules and we will try our best to implement a GUI, however since we haven't learned anything about GUIs we have no promises. 


How to Run:
  
Dependicies:

System Requirements:

Group Members:

  David Gerstle (https://github.com/gerstled)
  Raul Amaya (https://github.com/ramaya38)
  Oliver Collins (https://github.com/OliverCollins)
