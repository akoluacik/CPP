#include <iostream>
#include "HealthProfile.h"

int main()
{
    std::string name, surname, gender;
    int month, day, year;
    double weight, height;
    std::cout << "Enter your name, surname, gender: ";
    std::cin >> name >> surname >> gender;

    std::cout << "Enter your month, day and year of your birthday(respectively): ";
    std::cin >> month >> day >> year;

    std::cout << "Enter your weight and height: ";
    std::cin >> weight >> height ;

    HealthProfile hp = HealthProfile( name, surname, gender, month, day, year, height, weight );
    hp.displayInfo();
}