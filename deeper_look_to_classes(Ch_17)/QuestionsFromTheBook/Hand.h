#include "Card.h"

#ifndef HAND_H
#define HAND_H

typedef enum {
    NOTHING     = -1,
    STRAIGHT    =  0,
    THREE_KIND  =  1,
    FOUR_KIND   =  2,
    FLUSH       =  3,
} HandKind;

class Hand
{
private:
    Card* cards = new Card[5];
public:
    Hand(Card []);
    int containsHowManyPairs() const;
    HandKind containsThreeKind() const;
    HandKind containsFourKind() const;
    HandKind containsFlush() const;
    HandKind containsStraight() const;
    void displayHand() const;
    Card* getCards() const;
};

#endif