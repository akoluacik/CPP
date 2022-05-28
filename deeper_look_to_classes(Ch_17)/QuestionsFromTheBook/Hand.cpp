#include "Hand.h"
#include "Card.h"
#include <iostream>

Hand::Hand(Card cardss[5]) {
    
    for (size_t i = 0; i < 5; i++)
    {
        cards[i] = Card(cardss[i].getFace(), cardss[i].getSuit());
    }
    
}

int Hand::containsHowManyPairs() const{
    int count = 0;
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = i + 1; j < 5; j++)
        {
            if(cards[i].getFace() == cards[j].getFace() && 
                    cards[i].getSuit() == cards[j].getSuit()) ++count;
        }
    }
    return count;
}

bool Hand::containsThreeKind() const{
    int count = 0;
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = i + 1; j < 5; j++)
        {
            if(cards[i].getSuit() == cards[j].getSuit()) ++count;
        }
        if(count == 3) return true; else count = 0;
    }
    return false;
}

bool Hand::containsFourKind() const{
    int count = 0;
    for (size_t i = 0; i < 4; i++)
    {
        count = 0;
        for (size_t j = i + 1; j < 5; j++)
        {
            if(cards[i].getSuit() == cards[j].getSuit()) ++count;
        }
        if(count == 3) {
            return true;
        } else if (i == 3) {
            return false;
        }
    }
    return false;
}

bool Hand::containsFlush() const {
    int prev_suit = cards[0].getSuit();
    
    for (size_t i = 1; i < 5; i++)
    {
        if( prev_suit != cards[i].getSuit() ) return false;
    }

    return true;
}

bool Hand::containsStraight() const {
    
    int sortedFaces[5];
    
    for (size_t i = 0; i < 5; i++)
    {
        sortedFaces[i] = cards[i].getFace();
    }
    


    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = i + 1; j < 5; j++)
        {
            if (sortedFaces[i] < sortedFaces[j])
            {
                std::swap(sortedFaces[i], sortedFaces[j]);
            }
        }
    }
            
    for (size_t i = 0; i < 4; i++)
    {
        if (sortedFaces[i] - sortedFaces[i + 1] != 1) return false;
    }
    return true;
}

void Hand::displayHand() const {
    
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << cards[i].toString() << std::endl;
    }
    
}