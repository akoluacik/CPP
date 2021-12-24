#include <iostream>
#include "Date.h"

Date::Date(int _month, int _day, int _year)
{
    setMonth(_month);
    setDay(_day);
    setYear(_year);
}

void Date::setMonth(int _month)
{
    if(_month < 1 || _month > 12) month = 1; else month = _month;
}

void Date::setDay(int _day)
{
    if(_day < 1 || _day > 30) day = 1; else day = _day;
}

void Date::setYear(int _year)
{
    if(_year < 0) year = 0; else year = _year;
}

int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
int Date::getYear() const { return year; }

void Date::displayDate() const {
    std::cout << getMonth() << "/" << getDay() << "/" << getYear() << std::endl;
}