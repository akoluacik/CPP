#include "Card.h"

Card::Card( int face, int suit ) 
{
    this->face = face;
    this->suit = suit;
}

std::string Card::toString() const {
    return this->faces[face] + " of " + this->suits[suit];
}

void Card::setFace( int face ) {
    this->face = face;
}

void Card::setSuit( int suit ) {
    this->suit = suit;
}

int Card::getFace() const {
    return face;
}

int Card::getSuit() const {
    return suit;
}


std::string Card::faces[13] = {"1", "2", "3", "4", "5", "6", "7" ,"8", "9", "10", "11", "12", "13"};
std::string Card::suits[4] = {"Clubs", "Hearts", "Spades", "Diamods"};