#include "Game.h"
#include "Decks.h"
#include <iostream>
#include <limits.h>
#include <stdlib.h>
using namespace std;

Game::Game(int playernum, int money)
{
    //ctor
    cin.ignore();
    for (int p = 0; p<playernum; p++){
        string name;
        cout<<"Enter Player "<<p+1<<" name: ";
        getline(cin, name);
        Player* temp = new Player;
        temp->name = name;
        temp->money = money;
        temp->first = NULL;
        temp->BJ = false;
        temp->hasAce = false;
        players.push_back(temp);
    }
    Player* dealer = new Player;
    dealer->name = "Dealer";
    dealer->money = INT_MAX;
    dealer->first = NULL;
    dealer->bet = 0;
    dealer->BJ=false;
    dealer->hasAce = false;
    players.push_back(dealer);
}

Game::~Game()
{
    //dtor
}

void Game::dealRound(int playernum, Decks *deck){
    for (int h = 0; h<playernum; h++){
        Card* temp = deck->dealCard();
        players[h]->first = temp;
    }
    for (int h = 0; h<playernum; h++){
        Card* temp = deck->dealCard();
        players[h]->first->next = temp;
    }
}

void Game::placeBets(int playernum){
    cout<<endl;
    cout<<"***Minimum bet is $10***"<<endl;
    string bet;
    int betint;
    for (int j=0;j<playernum;j++){
        bool goodbet = false;
        while (goodbet == false){
            cout<<players[j]->name<<", what would you like to bet?  ";
            cin>>bet;
            betint = atoi(bet.c_str());
            while (betint < 10 || betint > players[j]->money ){
                if (betint < 10){
                    cout<<"The minimum bet is $10. Please enter your bet: ";
                }
                else if (betint > players[j]->money){
                    cout<<"You don't have that much money! You only have $"<<players[j]->money<<". Please enter your bet: ";
                }
                    cin>>bet;
                    betint = atoi(bet.c_str());
            }
            if (betint >=10 && betint <=players[j]->money){
                players[j]->bet = betint;
                goodbet = true;
            }
        }

    }
}

void Game::showDealerHand(Decks *deck){
    cout<<"Dealer is showing a ";
    deck->printCard(players.back()->first);
}

void Game::showPlayerHand(Player* player, Decks *deck){
    int sum = 0;
    cout<<"you have:"<<endl;
    Card* temp = player->first;
    while (temp!=NULL){
        if (temp->value == 14){
            player->hasAce = true;
        }
        sum = sum + temp->points;
        deck->printCard(temp);
        temp= temp->next;
    }if (player->hasAce == true && player->sum ==11) {
        player->BJ = true;
    }
    else if (player->hasAce == true && player->sum <11) {
        cout<<"The total of your hand is: "<<sum<<" or "<<sum+10<<endl;
    }else{
        cout<<"The total of your hand is: "<<sum<<endl;
    }
    player->sum = sum;

}

void Game::revealDealerHand(Player *dealer, Decks *deck){
    int sum = 0;
    cout<<"Dealer has:"<<endl;
    Card* temp = dealer->first;
    while (temp!=NULL){
        if (temp->value == 14){
            dealer->hasAce = true;
        }
        sum = sum + temp->points;
        deck->printCard(temp);
        temp= temp->next;
    }if (dealer->hasAce == true && dealer->sum ==11) {
        dealer->BJ = true;
        cout<<"Dealer got BLACKJACK!"<<endl;
    }
    else if (dealer->hasAce == true && dealer->sum +10 >= 17) {
        cout<<"Dealer has total of: "<<sum+10<<endl;
        dealer->sum = dealer->sum+10;
    }else{
        cout<<"Dealer has total of: "<<sum<<endl;
        dealer->sum = sum;
    }

}

void Game::hit(Player* player, Decks *deck){
    Card* temp = player->first->next;
    while (temp->next != NULL){
        temp = temp->next;
    }
    Card* newcard = deck->dealCard();
    temp->next = newcard;
    player->sum = player->sum + temp->next->points;
    cout<<"Dealt the ";
    deck->printCard(temp->next);
    if (temp->next->value == 14){
        player->hasAce = true;
    }
    if (player->hasAce == true && player->sum==11){
        cout<<"Your new total is: "<<player->sum+10<<endl;
    player->sum = player->sum +10;
    }
    if (player->hasAce == true && player->sum<=11){
        cout<<"Your new total is: "<<player->sum<<" or "<<player->sum + 10<<endl;
    }else{
        cout<<"Your new total is: "<<player->sum<<endl;
    }
}

void Game::hitDealer(Player* player, Decks *deck){
    cout<<"Dealer is hitting"<<endl;
    Card* temp = player->first->next;
    while (temp->next != NULL){
        temp = temp->next;
    }
    Card* newcard = deck->dealCard();
    temp->next = newcard;
    player->sum = player->sum + temp->next->points;
    cout<<"Dealt the ";
    deck->printCard(temp->next);
    if (temp->next->value == 14){
        player->hasAce = true;
    }
    if (player->hasAce == true && player->sum==11){
        cout<<"Dealer's new total is: "<<player->sum+10<<endl;
        player->sum = player->sum +10;
    }
    if (player->hasAce == true && player->sum<=11){
        cout<<"Dealer's new total is: "<<player->sum + 10<<endl;
    }else{
        if(player->sum > 21){
            player->bust = true;
            cout<<"Dealer BUSTED!"<<endl;
        }else{
            cout<<"Dealer's new total is: "<<player->sum<<endl;
        }
    }
}

void Game::hitOrStay(Player *player, Decks *deck){

    cout<< player->name <<", ";
    showPlayerHand(player, deck);
    if (player->BJ == true){
        cout<<"You have Blackjack! Congratulations!"<<endl;
    }else{
        string hos;
        bool turn = true;
        while (turn == true){
            if (!cin){
                cin.clear();
            }
            cin.ignore();
            cout<< "Press 1 to Hit, or 2 to Stay: ";
            cout<<endl;
            cin>>hos;
            if (hos == "1"){
                hit(player, deck);
            }else if (hos == "2"){
                turn = false;
                if (player->hasAce == true && player->sum<=11){
                    player->sum = player->sum + 10;
                }
            }else{
                cout<<"Please choose a valid option"<<endl;
            }
            if (player->sum == 21){
                cout<<"Nice!"<<endl;
                turn = false;
            }
            if (player->sum > 21){
                player->bust = true;
                cout<< "BUST"<<endl;
                turn = false;
            }
        }
    }
}

void Game::determineWins(Player* player, Player* dealer, Decks *deck){
    if (player->BJ == true){
        player->money = player->money + 1.5*player->bet;
        cout<< player->name<<", you got BLACKJACK! You now have: $"<<player->money<<endl;
    }else if (player->bust == true){
        player->money = player->money - player->bet;
        cout<< player->name<<", you busted. You now have: $"<<player->money<<endl;
    }else if (dealer->bust == true){
        player->money = player->money + player->bet;
        cout<<player->name<<", you won! You now have: $"<<player->money<<endl;
    }else if (dealer->sum > player->sum){
        player->money = player->money - player->bet;
        cout<<player->name<<", you lost. You now have: $"<<player->money<<endl;
    }else if (dealer->sum < player->sum){
        player->money = player->money + player->bet;
        cout<< player->name<<", you won! You now have: $"<<player->money<<endl;
    }else if (dealer->sum == player->sum){
        cout<<player->name<<", you pushed, you still have: $"<<player->money<<endl;
    }
    player->bet = 0;
    cout<<endl;

}


void Game::playRound(int playernum, Decks *deck){
    Player *dealer = players[playernum];
    int choice;
    bool exit = false;
    while (exit == false){
        for(int d = 0; d<playernum+1; d++){
            players[d]->sum = 0;
            players[d]->bet = 0;
            players[d]->BJ = false;
            players[d]->hasAce = false;
            players[d]->bust = false;
        }
        placeBets(playernum);
        cout<<endl;
        dealRound(playernum+1, deck);
        showDealerHand(deck);
        cout<<endl;
        for (int p = 0; p<playernum; p++){
            hitOrStay(players[p], deck);
            cout<<endl;
        }
        revealDealerHand(dealer, deck);
        while (dealer->sum < 17){
            hitDealer(dealer, deck);
        }
        cout<<endl;
        for (int y = 0; y<playernum; y++){
            determineWins(players[y], dealer, deck);
        }
        bool good = false;
        while (good == false){

            cout<<"1. Play another round"<<endl;
            cout<<"2. Exit to main menu"<<endl;
            cin.ignore();
            cin>>choice;
            if (choice == 2){
                    cout<<"Goodbye!"<<endl;
                    good = true;
                    exit = true;
            }
            else if (choice ==1 ){
                good = true;
            }
            else if (choice != 1 || choice != 2){
                cout<<"Please enter a valid choice"<<endl;
            }
        }
    }
}


