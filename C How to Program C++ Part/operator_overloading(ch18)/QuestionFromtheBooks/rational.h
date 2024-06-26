#ifndef __RATIONAL_H
#define __RATIONAL_H

#include <iostream>

class rational
{
private:
    friend std::ostream &operator<<(std::ostream &output, const rational &);
    friend std::istream &operator>>(std::istream &input, rational &);

    int num;
    int denum;
    int gcd(int,int);
    int lcm(int,int);
    void reduce_handler(rational &);

public:
    explicit rational(int = 0, int = 1);
    
    rational operator+(const rational &rat);
    rational operator-(const rational &rat);
    rational operator*(const rational &rat);
    rational operator/(const rational &rat);
    
    const rational& operator=(const rational &rat);
    
    bool operator==( const rational &rat ) const ;
    bool operator!=( const rational &rat ) const ;
    bool operator<( const rational &rat ) const ;
    bool operator>( const rational &rat ) const ;
    bool operator<=( const rational &rat ) const ;
    bool operator>=( const rational &rat ) const ;
};


#endif