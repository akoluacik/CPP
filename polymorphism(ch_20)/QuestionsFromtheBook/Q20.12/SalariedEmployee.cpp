#include <iostream>
#include <stdexcept>
#include "SalariedEmployee.h"
//#include "Date.h"

SalariedEmployee::SalariedEmployee(const std::string &first,
        const std::string &last, const std::string &ssn, Date& date, double salary )
        : Employee( first, last, ssn, date )
{
    setWeeklySalary( salary );
}

// set salary
void SalariedEmployee::setWeeklySalary( double salary ) {
    if ( salary >= 0.0 )
        weeklySalary = salary;
    else
        throw std::invalid_argument( "Weekly salary must be >= 0.0" );
} // end function setWeeklySalary

// return salary
double SalariedEmployee::getWeeklySalary() const {
    return weeklySalary;
} // end function getWeeklySalary

// calculate earnings;
// override pure virtual function earnings in Employee
double SalariedEmployee::earnings() const {
    double res = getWeeklySalary();
    if( Employee::getCurrentMonth() == Employee::getBirthDate().getMonth() )
        res += 100;
    return res;
} // end function earnings

// print SalariedEmployee's information
void SalariedEmployee::print() const {
    std::cout << "salaried employee: ";
    Employee::print(); // reuse abstract base-class print function
    std::cout << "\nweekly salary: " << getWeeklySalary();
} // end function print