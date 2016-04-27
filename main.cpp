#include <iostream>
#include "Decks.h"
#include <iostream>
#include <stdlib.h>
#include <Game.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(0));
    int choice;
    bool exit = false;
    //display menu
    while (exit == false){
        cout<<"======Blackjack Menu======"	<<	endl;
        cout<<"1. Start New Blackjack Game"	<<	endl;
        cout<<"2. Quit"	<<	endl;

    cin>>choice;
        if(choice == 1){
            string deck, play, money;
            cout<<"Enter the number of decks you would like to play with: ";
            cin>>deck;
            int decknum = atoi(deck.c_str());
            Decks newdeck(decknum);
            newdeck.shuffleDecks();
            //newdeck.printDecks();

            cout<<"Enter number of players: ";
            cin>>play;
            int playerint = atoi(play.c_str());
            int moneyint = 0;
            while (moneyint <10 ){
                cout<<"Enter the amount of money for each player to start with (min. $10): ";
                cin>>money;
                moneyint = atoi(money.c_str());
                if (moneyint < 10){
                    cout<<"Players must start with at least $10."<<endl;
                }
            }

            Game game(playerint, moneyint);
            game.playRound(playerint, &newdeck);



        }
        else if (choice ==2){
            exit = true;
            cout<<"Goodbye!"<<endl;
        }
        else{
            cout<<"Please enter a valid choice"<<endl;
        }


    }

}
