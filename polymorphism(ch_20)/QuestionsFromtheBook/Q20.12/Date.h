#if !defined(__DATE_H)
#define __DATE_H

#include <array>
#include <iostream>

class Date
{
private:
    friend std::ostream &operator<<( std::ostream &, const Date &);
    unsigned int month;
    unsigned int day;
    unsigned int year;
    static const std::array < unsigned int, 13 > days; // days per month
    void helpIncrement(); // utility function incrementing date

public:
    Date( int m = 1, int d = 1, int y = 1900 ); // Default ctor
    void setDate( int, int, int );
    Date &operator++(); // prefix increment operator
    Date operator++( int ); // postfix increment operator
    Date &operator+=( unsigned int ); // add days, modify object
    static bool leapYear( int );
    bool endOfMonth( int ) const;
    int getMonth() const;
    int getDay() const;
    int getYear() const;
};

#endif // __DATE_H
