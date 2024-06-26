#if !defined(__EMPLOYEE_H)
#define __EMPLOYEE_H

#include <string>

class Employee
{
private:
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;
    
public:
    //Employee();
    Employee(const std::string &, const std::string &, const std::string & );
    
    void setFirstName( const std::string & ); // set first name
    std::string getFirstName() const; // return first name

    void setLastName( const std::string & ); // set last name
    std::string getLastName() const; // return last name

    void setSocialSecurityNumber( const std::string & ); // set SSN
    std::string getSocialSecurityNumber() const; // return SSN

    
};

#endif // __EMPLOYEE_H
