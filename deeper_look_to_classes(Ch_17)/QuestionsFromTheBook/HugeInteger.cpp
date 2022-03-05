// HugeInteger.cpp
// Methods' body definitions

#include "HugeInteger.h"
#include <iostream>
#include <sstream>
#include <string>
// Utility contains the functions that checks if a number greater, equal, or less than the other
#include "HugeIntegerUtility.h"

void HugeInteger::Input()
{
    std::string input;
    std::getline(std::cin, input);

    len = input.length();
    
    // std::istringstream iss{input};

    for (size_t i = 0; i < len; ++i)
    {
        arr[40 - len + i] = input[i] - '0';
        //std::cout << "i:" << i << "arr[" << 40 - len + i << "] : " << arr[40 - len + i] << std::endl;
        //std::cout << "i:" << i << " input[" << i << "]: " << input[i] << std::endl;
    }
}

void HugeInteger::Output() const
{
    for (size_t i = 40 - len; i < 40; i++)
    {
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

bool HugeInteger::isEqual( HugeInteger HI ) const
{
    if ( HI.len != len) return false;
    for (size_t i = (40 - 1) - len; i < 40; i++)
    {
        if ( !eq(arr[i], HI.arr[i]) ) return false;
    }
    return true;   
}

bool HugeInteger::isNotEqual( HugeInteger HI ) const { return !isEqual(HI); }

bool HugeInteger::isGreater ( HugeInteger HI ) const 
{
    if ( HI.len > len ) return false;

    else if ( len > HI.len) return true;
    
    for (size_t i = (40 - 1) - len; i < 40; i++) // if lengths are equal
    {
        if ( less(arr[i], HI.arr[i] ) ) return false;
    }
    
    return true;
}

bool HugeInteger::isGreaterThanorEqualTo( HugeInteger HI ) const
{
    return isEqual( HI ) || isGreater( HI );
}

bool HugeInteger::isLessThan( HugeInteger HI ) const
{
    return isNotEqual( HI ) && !isGreaterThanorEqualTo( HI ); // true if not equal AND not greater
}

bool HugeInteger::isLessThanorEqualTo ( HugeInteger HI ) const
{
    return isEqual( HI ) || isLessThan( HI );
}

void HugeInteger::Add( HugeInteger HI ) const
{
    int length = (len > HI.len) ? len : HI.len;
    int result[40] = {0};
    int carry = 0;
    size_t i; // iterator index

    for (i = 39 ; i >= (40 - length); i--)
    {
        result[i] = carry + (arr[i] + HI.arr[i]) % 10;
        carry = (arr[i] + HI.arr[i]) / 10;
    }
    
    result[i] = carry; // write carry out as most significant bit
    i = carry ? i : i + 1;
    
    for (; i < 40; i++)
    {
        std::cout << result[i];
    }
    
    std::cout << std::endl;
}

void HugeInteger::Substract( HugeInteger HI ) const
{
    int length = (len > HI.len) ? len : HI.len;
    int result[40] = {0};
    int temp[40]; // holds minuend, and not to change the attribute due to the 'const'.
    int borrow = 0;
    size_t i; // iterator index

    if ( isEqual( HI ) ) std::cout << 0;    

    // if minuend > subtrahend
    else if ( isGreater( HI ) ) 
    {
        std::copy(std::begin(arr), std::end(arr), std::begin(temp));

        for (size_t i = (40 - 1); i >= (40 - 1) - length; i--)
        {
            if( greater( HI.arr[i], temp[i] ) ){
                temp[i] += 10;
                temp[i - 1]--;
            }
            result[i] = temp[i] - HI.arr[i];
        }
    }
    
    // if minuend < subtrahend
    else
    {
        std::copy(std::begin(HI.arr), std::end(HI.arr), std::begin(temp));
        for (size_t i = (40 - 1); i >= (40 - 1) - length; i--)
        {
            if( greater( arr[i], temp[i] ) ){
                temp[i] += 10;
                temp[i - 1]--;
            }
            result[i] = temp[i] - arr[i];
        }
        std::cout << "-";
    }
    
    // print the result
    for (size_t i = (40 - 1) - length, j = 0; i < 40; i++)
    {
        if( j == 0 && result[i] == 0) // not to write the 0s at the beginning
        {
            j = 0; // flag variable
            continue;
        }
        j = 1; // now 0s between two numbers and the end will be printed.
        std::cout << result[i];
    }
    std::cout << std::endl;
}

// 0001