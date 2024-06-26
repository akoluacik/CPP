#include <string>

#ifndef CARD_H
#define CARD_H

class Card
{
private:
    int face;
    int suit;
    static std::string faces[13];
    static std::string suits[4];

public:
    Card() = default;
    Card( int , int );
    std::string toString() const;
    void setFace(int );
    void setSuit(int );
    int getFace() const;
    int getSuit() const;


};

#endif