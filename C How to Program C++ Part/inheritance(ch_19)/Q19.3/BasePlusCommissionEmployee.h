#ifndef __BASE_PLUS_COMMISION_EMPLOYEE_H
#define __BASE_PLUS_COMMISION_EMPLOYEE_H

#include "CommisionEmployee.h"
#include "Employee.h"

class BasePlusCommissionEmployee
{
private:
    CommisionEmployee come;
    double baseSalary; // base salary
    
public:
    BasePlusCommissionEmployee( CommisionEmployee, double = 1000 );
    void setBaseSalary( double ); // set base salary
    double getBaseSalary() const; // return base salary

    double earnings() const; // calculate earnings
    void print() const; // print CommissionEmployee object

};

#endif