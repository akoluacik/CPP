#ifndef __COMMISION_EMPLOYEE_H
#define __COMMISION_EMPLOYEE_H


#include "Employee.h"

class CommisionEmployee
{
private:
    Employee emp;
    double grossSales; // gross weekly sales
    double commissionRate; // commission percentage
    
public:
    CommisionEmployee(Employee , double = 0, double = 0);
    
    void setGrossSales( double ); // set gross sales amount
    double getGrossSales() const; // return gross sales amount
    Employee getEmployee() const;

    void setCommissionRate( double ); // set commission rate (percentage)
    double getCommissionRate() const; // return commission rate

};

#endif