#ifndef __SALARIED_H
#define __SALARIED_H

#include <string>
#include "Employee.h"

class SalariedEmployee : public Employee
{
private:
    double weeklySalary;
public:
    SalariedEmployee( const std::string &, const std::string &,
                      const std::string &, Date& , double = 0.0 );
    virtual ~SalariedEmployee(){ }

    void setWeeklySalary( double ); // set weekly salary
    double getWeeklySalary() const; // return weekly salary

    // keyword virtual signals intent to override
    virtual double earnings() const override; 
    virtual void print() const override;

};

#endif