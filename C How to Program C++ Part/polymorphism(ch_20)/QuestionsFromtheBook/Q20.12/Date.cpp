#include <iostream>
#include <string>
#include "Date.h"

const std::array < unsigned int, 13 > Date::days = 
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date( int month, int day, int year )
{
    setDate( month, day, year );
}

void Date::setDate( int mm, int dd, int yy )
{
    // Sanity checkings
    if( mm >= 1 && mm <= 12 )
        month = mm;
    else
        throw std::invalid_argument("Month must be 1-12");
    
    if( yy >= 1900 && yy <= 2100 )
        year = yy;
    else 
        throw std::invalid_argument("Year must be >= 1900 and <= 2100" );
    
    // test for leap year
    if ( ( month == 2 && leapYear( year ) && dd >= 1 && dd <= 29 ) || 
         ( dd >= 1 && dd <= days[month] ) )
         day = dd;
    else 
        throw std::invalid_argument( "Day is out of range for current month and year" );
    
}

// Overload prefix increment operator
Date &Date::operator++()
{
    helpIncrement();
    return *this; // reference return to crean an lvalue
}

// Overloaded postfix increment operator, note that dummy
// integer parameter does not ave a parameter name

Date Date::operator++( int ) {
    Date temp = *this; // hold current state of object
    helpIncrement();

    // return unincremented save temp object
    return temp;
}

// add specified number of days to date
Date &Date::operator+=( unsigned int addDays ) {
    
    for (size_t i = 0; i < addDays; i++)
    {
        helpIncrement();
    }

    return *this; // enables cascading
}

// if the year is leap year, return true
bool Date::leapYear( int testYear ) {
    if ( testYear % 400 == 0 || 
       ( testYear % 100 != 0 && testYear % 4 == 0) )
        return true;
    else
        return false;
    
}

// determine if the day is the last of the month
bool Date::endOfMonth( int testDay ) const {
    if ( month == 2 && leapYear( year ))
        return testDay == 29;
    return testDay == days[month];
}

// function to help increment daye
void Date::helpIncrement() {
    // day is not end of month
    if( !endOfMonth(day) )
        ++day;
    else {
        if( month < 12 ) {
            ++month; // increment month
        } else {
            ++year;
            month = 1;
        }
        day = 1;
    }
}

std::ostream &operator<<( std::ostream & output, const Date &d) {
    static std::string monthName[13] = { "", "January", "February",
        "March", "April", "May", "June", "July", "August",
        "September", "October", "November", "December" };
    output << monthName[d.month] << ' ' << d.day << ", " << d.year;
    return output;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

int Date::getYear() const {
    return year;
}