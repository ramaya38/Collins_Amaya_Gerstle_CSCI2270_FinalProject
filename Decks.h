#ifndef DECKS_H
#define DECKS_H
#include <vector>
#include <string>

using namespace std;

struct Card{
    int value;
    int suit;
    int points;
    Card* next;
};


class Decks
{
    public:
        Decks(int);
        ~Decks();
        void shuffleDecks();
        void printDecks();
        void printCard(Card*);
        string toString(int);
        Card* dealCard();
    protected:

    private:
        vector<Card*> deckList;
};

#endif // DECKS_H
