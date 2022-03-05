// HugeInteger class definition
// Methods' body will be defined in HugeInteger.cpp

#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H


class HugeInteger
{
private:
    // least significant number will be at the last index.
    // most significant bit will be in the ((40 - 1) - len) th index.
    int arr[40] = {0}; 
    int len = 0;
public:
    void Input();
    void Output() const;
    void Add( HugeInteger ) const;
    void Substract( HugeInteger ) const;
    bool isEqual( HugeInteger ) const;
    bool isNotEqual( HugeInteger ) const;
    bool isGreater( HugeInteger ) const;
    bool isGreaterThanorEqualTo( HugeInteger ) const;
    bool isLessThan( HugeInteger ) const;
    bool isLessThanorEqualTo( HugeInteger ) const;
};

#endif