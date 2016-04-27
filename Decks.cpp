#include "Decks.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

Decks::Decks(int number)
{
    //ctor
    for (int x = 0; x<number; x++){
        for (int v = 2; v<15; v++){
            for (int s = 0; s<4; s++){
                Card* temp = new Card;
                temp->value = v;
                temp->suit = s;
                temp->next = NULL;
                if (v < 11){
                    temp->points = v;
                }else if (v<14){
                    temp->points = 10;
                }else{
                    temp->points = 1;
                }
                deckList.push_back(temp);
            }
        }
    }
}

Decks::~Decks()
{
    //dtor
}

void Decks::printDecks(){

    for (int d = 0; d<deckList.size(); d++){
        printCard(deckList[d]);
    }

}

string Decks::toString(int a){
    stringstream stream;
    stream << a;
    return stream.str();
}

void Decks::printCard(Card* card){
    string suitText;
    string valueText;
    if (card->suit == 0){
        suitText = "spades";
    }
    else if (card->suit == 1){
        suitText = "clubs";
    }
    else if (card->suit == 2){
        suitText = "hearts";
    }
    else if (card->suit == 3){
        suitText = "diamonds";
    }
    if (card->value < 11){
        valueText = toString(card->value);
    }else if (card->value == 11){
        valueText = "Jack";
    }
    else if (card->value == 12){
        valueText = "Queen";
    }
    else if (card->value == 13){
        valueText = "King";
    }
    else if (card->value == 14){
        valueText = "Ace";
    }

    cout<<valueText<<" of "<<suitText<<endl;

}

void Decks::shuffleDecks(){
    random_shuffle(deckList.begin(), deckList.end());
}

Card* Decks::dealCard(){
    Card* card = deckList[deckList.size()-1];
    deckList.pop_back();
    return card;
}


