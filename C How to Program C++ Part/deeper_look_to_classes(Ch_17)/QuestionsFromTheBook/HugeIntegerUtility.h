#ifndef UTILITY_H
#define UTILITY_H

bool eq( int n1, int n2 ) { return n1 == n2; }
bool greater( int n1, int n2 ) { return n1 > n2; }
bool less( int n1, int n2 ) { return n1 < n2; }

void substract( int *minuend, int *subtrahend , int length)
{
    int result[length] = {0};
    for (size_t i = length - 1; i >= 0 - length; i--)
    {
        if( greater( subtrahend[i], minuend[i] ) )
        {
            minuend[i] += 10;
            minuend[i - 1]--;
        }
        result[i] = minuend[i] - subtrahend[i];
    }
}

#endif