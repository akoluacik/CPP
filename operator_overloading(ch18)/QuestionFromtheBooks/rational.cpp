#include <iostream>
#include "rational.h"

rational::rational(int num, int denum)
    :num(num),
     denum(denum)
{
    if (this->denum < 0)
    {
        
        this->denum = -this->denum;
        this->num = -this->num;
        
    }
    
    int gcd = rational::gcd(num, denum);
    this->num = this->num / gcd;
    this->denum = this->denum / gcd;
}

std::ostream &operator<<( std::ostream &output, const rational &rat ) {
    
    output << rat.num << "";
    if(rat.denum != 1) {
        output << "/" << rat.denum;
    }
    output << std::endl;
    return output;
}

std::istream &operator>>( std::istream &input, rational &rat ) {
    input >> rat.num >> rat.denum;
    return input;
}

int rational::gcd( int num, int denum ) {
    if (denum == 0)
    return num;
    return gcd(denum, num % denum);
}

int rational::lcm( int denum1, int denum2 ) {
    return (denum1 * denum2) / gcd(denum1, denum2);
}

rational rational::operator+(const rational &rat) {
    int res_num, res_denum;
    
    if(denum != rat.denum) {
        res_denum = rational::lcm(denum, rat.denum); // the same denum.
        res_num = (num * res_denum) / denum + (rat.num * res_denum) / rat.denum; // expanding the numerators
    } else {
        res_denum = denum;
        res_num = num + rat.num;
    }

    return rational(res_num, res_denum); // obtain the simplified version.
}

rational rational::operator-( const rational &rat ) {
    int res_num, res_denum;
    
    if(denum != rat.denum) {
        res_denum = rational::lcm(denum, rat.denum); // the same denum.
        res_num = (num * res_denum) / denum - (rat.num * res_denum) / rat.denum; // expanding the numerators
    } else {
        res_denum = denum;
        res_num = num - rat.num;
    }

    return rational(res_num, res_denum); // obtain the simplified version.
}

const rational& rational::operator=( const rational& rat) {
    if(&rat != this) {
        num = rat.num;
        denum = rat.denum;
    }
    return *this;
}

rational rational::operator*( const rational &rat ) {
    return rational(num * rat.num, denum * rat.denum); // obtain the simplified version.
}

rational rational::operator/( const rational &rat ) {
    return rational(num * rat.denum, denum * rat.num); // obtain the simplified version.
}

bool rational::operator==( const rational &rat ) const {
    return ( ( num / denum ) && ( rat.num / rat.denum ) );
}

bool rational::operator!=( const rational &rat ) const {
    return !(*this == rat);
}

bool rational::operator<( const rational &rat ) const {
    return (num / (double)denum) < (rat.num / (double)rat.denum);
}

bool rational::operator>( const rational &rat ) const {
    return (num / (double)denum) > (rat.num / (double)rat.denum);
}

bool rational::operator<=(const rational &rat ) const {
    return rational::operator<(rat) || rational::operator==(rat);
}

bool rational::operator>=(const rational &rat ) const {
    return rational::operator>(rat) || rational::operator==(rat);
}

