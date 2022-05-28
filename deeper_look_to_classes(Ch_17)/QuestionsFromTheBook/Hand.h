#include "Card.h"

#ifndef HAND_H
#define HAND_H

class Hand
{
private:
    Card cards[5];
public:
    Hand(Card []);
    int containsHowManyPairs() const;
    bool containsThreeKind() const;
    bool containsFourKind() const;
    bool containsFlush() const;
    bool containsStraight() const;
    void displayHand() const;
};

#endif