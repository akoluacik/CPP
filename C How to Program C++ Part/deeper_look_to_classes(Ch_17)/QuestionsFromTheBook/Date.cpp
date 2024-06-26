// Date.cpp
// Date class member-function definitions.
// ctor overloading will be handled soon.

#include <array>
#include <iostream>
#include <stdexcept>
#include "Date.h"
#include <iomanip>
#include <ctime>

Date::Date()
{
    time_t t = time(NULL);
    struct tm *time = localtime( &t );
    
    day = time -> tm_mday;
    month = time -> tm_mon + 1;
    year = time -> tm_year + 1900;
    dddYYYFormatHandler( day );
    print();
}

Date::Date( int mn, int dy, int yr )
{
    
    if( mn > 0 && mn <= monthsPerYear ) // validate the month
        month = mn;
    else
        throw std::invalid_argument("[ERROR] Month must be 1-12");
    
    year = yr;
    day = checkDay( dy ); // validate the day
    
    dddYYYFormatHandler( day );
    
    print();
    std::cout << std::endl;
}

void Date::print() const 
{
    int tempDay;
    std::cout << std::setw(3) << std::setfill('0')  << dayy << " " << year << std::endl;
    std::cout << std::setw(2) << std::setfill('0') << month << "/" 
            << std::setw(2) << std::setfill('0') << day << "/" 
            << std::setw(4) << std::setfill('0') << year << std::endl;
    std::cout << monthAsStr[ month - 1 ] <<  " " << day << ", " << std::setw(4) << std::setfill('0') << year;
}



// utility function to confirm proper day value based on
// month and year; handles leap year, too
unsigned int Date::checkDay( int testDay )
{
    static const std::array< int, monthsPerYear + 1 > daysPerMonth = 
        { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // determine if testDay is valid for specified month
    if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
        return testDay;
        
    // Februray 29 check for leap year
    if( month == 2 && testDay == 29 && (year % 400 == 0 || ( year % 4 == 0 && 
        year % 100 != 0 ) ) ) 
            return testDay;
        
    
    throw std::invalid_argument("[ERROR] Invalid day for current month and year");
}

void Date::dddYYYFormatHandler( int day )
{
    static const std::array< int, monthsPerYear + 1 > daysPerMonth = 
        { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (size_t i = 1; i < month; i++)
    {
        dayy += daysPerMonth[ i ];
    }
    dayy += day;

    if( (year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) ) && month > 2) 
            dayy++;
}