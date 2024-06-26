#include <iostream>
#include "DeckOfCards.h"
#include "Hand.h"

int main() {

    // DECK PREPARATION
    DeckOfCards doc = DeckOfCards();
    //doc.displayDeck();
    //std::cout << "After Shuffling: " << std::endl;
    srand(time(NULL));
    doc.shuffle();
    //doc.displayDeck();
    //std::cout << "Next card: " << doc.dealCard().toString() << std::endl;
    

    // DECK DEALING
    Hand hand1 = Hand(doc.dealCards(0));
    hand1.displayHand();
    
    //srand(time(NULL));
    Hand hand2 = Hand(doc.dealCards(4));
    hand2.displayHand();
 
    // WINNER DECISION
    int winner = doc.winnerDealer(hand1, hand2);
    if(winner == 0) {
        std::cout << "Draw" << std::endl;
    } else {
        std::cout << "Player-" << winner << " wins the game!" << std::endl;
    }

    // TODO: Deal the cards as faced down.
    return 0;
}