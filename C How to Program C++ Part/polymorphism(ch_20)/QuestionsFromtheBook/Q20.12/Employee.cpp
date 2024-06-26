#include <iostream>
#include "Employee.h"
#include <ctime>

Employee::Employee( const std::string &first, const std::string &last,
                    const std::string &ssn, Date& date)
    :firstName( first ), lastName( last ), socialSecurityNumber( ssn ), birthDate(date)
{
    // empty ctor body
}

// set first name
void Employee::setFirstName( const std::string &first ) {
firstName = first;
} // end function setFirstName

// return first name
std::string Employee::getFirstName() const {
    return firstName;
} // end function getFirstName

// set last name
void Employee::setLastName( const std::string &last ) {
    lastName = last;
} // end function setLastName

// return last name
std::string Employee::getLastName() const {
    return lastName;
} // end function getLastName

// set social security number
void Employee::setSocialSecurityNumber( const std::string &ssn ) {
    socialSecurityNumber = ssn; // should validate
} // end function setSocialSecurityNumber

// return social security number
std::string Employee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
} // end function getSocialSecurityNumber

void Employee::setBirthDate( Date _birthDate) {
    birthDate = _birthDate;
}

Date Employee::getBirthDate() const {
    return birthDate;
}

// print Employee's information (virtual, but not pure virtual)
void Employee::print() const {
    std::cout << getFirstName() << ' ' << getLastName() << " born in " << birthDate
<< "\nsocial security number: " << getSocialSecurityNumber();
}

int Employee::getCurrentMonth() const {
    time_t t = time(NULL);
    tm* now = localtime(&t);
    return now->tm_mon + 1;
}