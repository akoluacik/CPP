#include <iostream>

class Date
{
public:
    Date(int _month, int day, int year);
    /* Mutators starts */
    void setMonth(int _month);
    void setDay(int _day);
    void setYear(int _year);

    /* Accessors Starts */
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    void displayDate() const;
private:
    int month;
    int day;
    int year;
};