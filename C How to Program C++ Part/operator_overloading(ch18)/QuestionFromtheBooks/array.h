#ifndef __PARANTHESIS_H
#define __PARANTHESIS_H

#include <iostream>
#include <initializer_list>

class array
{
private:

    friend std::istream &operator>>( std::istream &, array &);
    friend std::ostream &operator<<( std::ostream &, const array & );

    //size_t size;
    size_t row;
    size_t col;

    double **ptr;

public:
    
    explicit array ( size_t = 1 , size_t = 6 );
    array( const array & );
    array( std::initializer_list <std::initializer_list<double>> list );
    ~array();

    size_t getSize() const;
    size_t getRow() const;
    size_t getColumn() const;

    double& operator()( size_t , size_t  );
    const array& operator=( const array&  );
    bool operator==(const array& ) const;
    bool operator!=(const array&) const;
    
};


#endif