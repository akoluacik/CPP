#include "Employee.h"
#include <iostream>
#include <stdexcept>

/*Employee::Employee() {
    Employee("default name", "Default surname", "default ssn");
}*/

Employee::Employee( const std::string &name, const std::string &lastName, const std::string &ssn )
        :firstName( name ),
         lastName( lastName ),
         socialSecurityNumber( ssn )
{
    // Empty ctor body
}

void Employee::setFirstName( const std::string &name ) {
    firstName = name;
}

std::string Employee::getFirstName() const {
    return firstName;
}

void Employee::setLastName( const std::string &_lastName ) {
    lastName = _lastName;
}

std::string Employee::getLastName() const {
    return lastName;
}

void Employee::setSocialSecurityNumber( const std::string &ssn ) {
    socialSecurityNumber = ssn;
}

std::string Employee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
}



