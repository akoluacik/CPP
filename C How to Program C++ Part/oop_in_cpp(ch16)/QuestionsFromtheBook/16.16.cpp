#include <iostream>

class HeartRates
{
private:
    std::string firstName;
    std::string lastName;
    int month;
    int day;
    int year;
    int age;

public:
    HeartRates(std::string fname, std::string lname, int month, int day, int year)
    {
        setFirstName(fname);
        setLastName(lname);
        setMonth(month);
        setDay(day);
        setYear(year);
    }
    
    /* Mutators Start */
    void setFirstName(std::string fname) {firstName = fname;}
    void setLastName(std::string lname) {lastName = lname;}
    void setMonth(int _month) 
    {
        if(_month < 1 || _month > 12) month = 1; else month = _month;
    }
    void setDay(int _day)
    {
        if(_day < 1 || _day > 30) day = 1; else day = _day;
    }
    void setYear(int _year) 
    {
        if(_year < 0) year = 0; else year = _year;
    }

    /* Accessors Start */
    std::string getFirstName() {return firstName;}
    std::string getLastName() {return lastName;}
    int getMonth() {return month;}
    int getDay() {return day;}
    int getYear() {return year;}

    void setAge(int currentYear = 2021) {
        age = currentYear - year;
    } 
    int getMaximumHeartRate() { return 220 - age;}
    void getTargetHeartRate() { 
        std::cout << "Target Heart Rate: (Between)" << (220 - age) * 0.5 << " and " << (220 - age) * 0.85 << std::endl;
    }
    void displayInfo()
    {
        setAge();
        std::cout << "Name: " << firstName 
            << "\nLast Name: " << lastName
            << "\nBirthday: " << month << day << year
            << "\nMax hearth rate : " << getMaximumHeartRate() << std::endl;
        getTargetHeartRate();

    }
};

int main()
{
    std::string name, surname;
    int month, day, year;
    std::cout << "Enter name, surname and your birthday as (MM/DD/YYYY): ";
    std::cin >> name >> surname >> month >> day >> year;
    HeartRates hr = HeartRates(name, surname, month, day, year);
    hr.displayInfo();
    return 0;
}