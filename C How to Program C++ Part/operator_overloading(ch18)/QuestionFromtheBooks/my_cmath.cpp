#include <iostream>
#include <stdlib.h>
#include <initializer_list>
#include "my_cmath.h"


complex_number::complex_number( int _real, int _complex ) { real = _real; complex = _complex; }

complex_number::complex_number( const complex_number &cn) 
    :complex(cn.complex),
     real(cn.real)
{
    // empty ctor body
}

complex_number::complex_number( std::initializer_list<int> cn){
    real = cn.begin()[0];
    complex = cn.begin()[1]; 
}

std::ostream &operator<<( std::ostream &output, const complex_number& cn) {
    std::string realPart = std::to_string(cn.real);
    std::string complexPart = "+j";

    if(cn.real == 0) realPart = "";
    
    if(cn.complex < 0) complexPart = "-j";
    complexPart += std::to_string(abs(cn.complex));
    
    if(cn.complex == 0) complexPart = "";
    
    output.precision(4);
    output << realPart << complexPart << std::endl;

    return output;
    
}

std::istream &operator>>( std::istream &input, complex_number &cn) {
    input >> cn.real >> cn.complex;
    return input;
}

const complex_number& complex_number::operator=( const complex_number& cn ) {
    
    if( &cn != this) {
        real = cn.real;
        complex = cn.complex;   
    }
    return *this;
}

complex_number complex_number::operator*( const complex_number &cn) {
    complex_number res;
    res.real = real * cn.real - cn.complex * complex;
    res.complex = complex * cn.real + cn.complex * real;;
    return res;
}

complex_number complex_number::operator+( const complex_number &cn) {
    complex_number res;
    res.real = real + cn.real;
    res.complex = complex + cn.complex;
    return res;
}

complex_number complex_number::operator-( const complex_number &cn ) {
    complex_number res;
    res.real = real - cn.real;
    res.complex = complex - cn.complex;
    return res;
}

complex_number complex_number::operator/( const complex_number &cn ) {

    double denum = cn.real * cn.real + cn.complex * cn.complex;
    double num_real = cn.real * real - (-cn.complex) * complex;
    double num_complex = cn.real * complex + (-cn.complex) * real;
    
    return complex_number(num_real / denum, num_complex / denum);
}

bool complex_number::operator==( const complex_number &cn ) const {
    return (cn.real == real && cn.complex == cn.complex);
}

bool complex_number::operator!=( const complex_number &cn ) const {
    return !(*this == cn);
}

