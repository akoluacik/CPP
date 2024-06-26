#include "maximum.h"
template < class T > // signle formal type parameter, T, which is a placeholder.
T maximum (T value1, T value2, T value3)
{
    T maximumValue = value1; // assume value1 is max
    
    if(value2 > maximumValue)
        maximumValue = value2;
    
    if(value3 > maximumValue)
        maximumValue = value3;
    
    return maximumValue;
}

template < class R, class S >
R pow (R base, S power)
{
    R res = 1;
    for (S i = 0; i < power; i++)
    {
        res *= base;
    }
    return res;
}