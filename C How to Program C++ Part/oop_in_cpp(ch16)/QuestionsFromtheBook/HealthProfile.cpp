#include "HealthProfile.h"
#include <iostream>
    HealthProfile::HealthProfile (std::string firstName, std::string lastName,
                std::string gender, int month, int day, int year, double height, double weight)
    {
        setFirstName(firstName);
        setLastName(lastName);
        setGender(gender);
        setBirthday(month, day, year);
        setHeight(height);
        setWeight(weight);
        setAge();
    }

    void HealthProfile::setFirstName(std::string fName) { firstName = fName; }
    void HealthProfile::setLastName(std::string lName) { lastName = lName; }
    void HealthProfile::setGender(std::string _gender) { gender = _gender; }
    void HealthProfile::setBirthday (int _month, int _day, int _year)
    {
        if(_month < 1 || _month > 12) month = 1; else month = _month;
        if(_day < 1 || _day > 30) day = 1; else day = _day;
        if(_year < 0) year = 0; else year = _year;
    }
    void HealthProfile::setHeight(double _height) { height = _height; }
    void HealthProfile::setWeight(double _weight) { weight = _weight; }
    void HealthProfile::setAge(int currentYear) { age = currentYear - year; }
    std::string HealthProfile::getFirstName() const { return firstName; }
    std::string HealthProfile::getLastName() const { return lastName; }
    std::string HealthProfile::getGender() const { return gender; }
    int HealthProfile::getMonth() const { return month; }
    int HealthProfile::getDay() const { return day; }
    int HealthProfile::getYear() const { return year; }
    double HealthProfile::getHeight() const { return height; }
    double HealthProfile::getWeight() const { return weight; }
    double HealthProfile::BMI() const { return (weight) / (height * height);}

    int HealthProfile::getMaximumHeartRate() const { return 220 - age; }
    double HealthProfile::getTargetHeartRate() const { return 0.7 * HealthProfile::getMaximumHeartRate();}

    void HealthProfile::displayInfo() const
    {
        std::cout << "Name: " << firstName 
            << "\nLast Name: " << lastName
            << "\nBirthday: " << month << "/" << day << "/" << year
            << "\nMax hearth rate : " << getMaximumHeartRate()
            << "\nTarget hearth rate : " << getTargetHeartRate() << std::endl;
    }
