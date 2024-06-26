#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <string>
#include "Date.h"

class Employee
{
private:
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;
    Date birthDate;
public:
    Employee(const std::string &, const std::string &,
             const std::string &, Date&);
    virtual ~Employee() { };

    void setFirstName( const std::string & ); // set first name
    std::string getFirstName() const; // return first name
    
    void setLastName( const std::string & ); // set last name
    std::string getLastName() const; // return last name
    
    void setSocialSecurityNumber( const std::string & ); // set SSN
    std::string getSocialSecurityNumber() const; // return SSN

    void setBirthDate ( Date );
    Date getBirthDate() const;

    // pure virtual function makes Employee an abstract base class
    virtual double earnings() const = 0; // pure virtual
    virtual void print() const; // virtual
    virtual int getCurrentMonth() const;
};


#endif