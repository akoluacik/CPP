#include "Card.h"
#include "Hand.h"

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

class DeckOfCards
{
private:
    Card deck[52];
    int currentCard = 0;
    Card hand[5];
    
public:
    DeckOfCards();
    //~DeckOfCards();
    void shuffle();
    Card dealCard();
    bool moreCards();
    void displayDeck();
    Card* dealCards(int);
    int winnerDealer(Hand, Hand);
};

#endif