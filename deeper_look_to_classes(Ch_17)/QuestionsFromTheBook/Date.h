// Date.h 
// Date class definition; Member functions is defined in Date.cpp
#include <string>
#ifndef DATE_H
#define DATE_H

class Date
{

public:
    static const int monthsPerYear = 12;
    Date();
    Date( int, int = 1990); // ctor for DDD YYYY format
    // Date ( const char *, int, int ); // default ctor for June 14, 1992
    Date( int, int = 1, int = 1990 ); // default constructor
    void print() const;
    //~Date(); 

private:
    unsigned int month;
    unsigned int day;
    unsigned int year;
    unsigned int dayy = 0; // DDD format
    unsigned int checkDay( int );
    const char *monthAsStr[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                            "July", "Aug", "Sep", "Oct", "Nov", "Dec"}; 
    void dddYYYFormatHandler( int );
};

#endif