#if !defined(__MY_CMATH_H)
#define __MY_CMATH_H

#include <iostream>
#include <initializer_list>

class complex_number
{
private:
    friend std::ostream &operator<<(std::ostream &output, const complex_number &);
    friend std::istream &operator>>(std::istream &input, complex_number &);

    double complex;
    double real;

public:
    complex_number( const complex_number &); // copy ctor
    explicit complex_number( int = 0, int = 0 );
    complex_number( std::initializer_list <int> cn); // initializer list for complex number
    ~complex_number() {}

    
    bool operator==( const complex_number &) const;
    bool operator!=( const complex_number &) const;
    
    const complex_number& operator=( const complex_number&  );
    complex_number operator*( const complex_number &);
    complex_number operator+( const complex_number &);
    complex_number operator-( const complex_number &);
    complex_number operator/( const complex_number &);
};

#endif // __MY_CMATH_H
