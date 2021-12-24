#include <iostream>
#include "Date.h"

int main()
{
    int month, day, year;
    for (size_t i = 0; i < 4; i++)
    {
        std::cin >> month >> day >> year;
        Date date = Date(month, day, year);
        date.displayDate();
    }
    
}