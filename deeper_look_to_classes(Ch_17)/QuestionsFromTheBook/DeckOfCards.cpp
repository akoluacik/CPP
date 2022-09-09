#include <iostream>
#include <cstdlib>
#include "DeckOfCards.h"
#include "Card.h"
#include "Hand.h"

DeckOfCards::DeckOfCards() {
    uint8_t idx = 0;
    
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 13; j++)
            deck[idx++] = Card(j, i);
}

void DeckOfCards::shuffle() {
    int rd = 0, tempFace, tempSuit;

    for (size_t i = 0; i < 52; i++)
    {
        /* random number generation */
        do
        {
            rd = rand() % 52;
        } while (rd == i);
        
        /* Swapping */
        tempFace = deck[rd].getFace();
        tempSuit = deck[rd].getSuit();
        deck[rd].setSuit(deck[i].getSuit());
        deck[rd].setFace(deck[i].getFace());
        deck[i].setFace(tempFace);
        deck[i].setSuit(tempSuit);

    }
    
}

Card DeckOfCards::dealCard() {
    return deck[currentCard++];
}

bool DeckOfCards::moreCards() {
    return currentCard != 51;
}

Card* DeckOfCards::dealCards(int idx) {
    // Card *card = (Card*)malloc(sizeof(Card) * 5);
    for (size_t i = idx, j = 0; i < idx + 5 && j < 5; i++, j++)
    {
        hand[j] = deck[i];
        //std::cout << card[i].getFace() << " of " << card[i].getSuit() << " ";
        //std::cout << hand[j].toString() << " ";
    }
    std::cout << std::endl;
    return hand;
}

void DeckOfCards::displayDeck() {
    for (size_t i = 0; i < 52; i++)
    {
        std::cout << deck[i].toString() << std::endl;
    }
}
uint8_t convertToPoints(Hand hand) {
    uint8_t count = 0;
    if (hand.containsFlush() == FLUSH)
    {
        std::cout << "The hand contains flush!" << std::endl;
        count += 8;
    } else if (hand.containsFourKind() == FOUR_KIND)
    {
        std::cout << "The hand contains four kind!" << std::endl;
        count += 7;
    } else if (hand.containsThreeKind() == THREE_KIND) {
        std::cout << "The hand contains three kind!" << std::endl;
        count += 6;
    } else if (hand.containsStraight() == STRAIGHT) {
        std::cout << "The hand contains straight!" << std::endl;
        count += 5;
    } else {
        int point = hand.containsHowManyPairs();
        if (point >= 1) {
            std::cout << "The hand contains " << hand.containsHowManyPairs() << " pairs!" << std::endl;
            count += (uint8_t)point;
        } else {
            std::cout << "Nothing special!" << std::endl;
        }
    }
    return count;
}

uint16_t DeckOfCards::totalPoints(Hand hand) {
    Card* cards = hand.getCards();
    uint16_t total = 0;
    
    for (size_t i = 0; i < 5; i++)
    {
        if(cards[i].getFace() == 1) total += 14; else total += cards[i].getFace();
    }
    
    return total;
}

int DeckOfCards::winnerDealer(Hand hand1, Hand hand2) {
    uint16_t points[2] = {0, 0};
    points[0] = convertToPoints(hand1);
    points[1] = convertToPoints(hand2);
    
    if(points[0] == points[1]) {
        points[0] = totalPoints(hand1);
        points[1] = totalPoints(hand2);
        std::cout << "Hand1: " << points[0] << " Hand2:" << points[1] << std::endl;
    }
    
    return (points[0] > points[1]) ? 1 : ((points[0] < points[1]) ? 2 : 0);
}