#ifndef __BASEPLUS_H
#define __BASEPLUS_H
#include <string> // C++ standard string class
#include "CommissionEmployee.h" // CommissionEmployee class definition

class BasePlusCommissionEmployee : public CommissionEmployee {
public:
    BasePlusCommissionEmployee( const std::string &, const std::string &, 
                    const std::string &, Date&, double = 0.0, double = 0.0, double = 0.0 );
    virtual ~BasePlusCommissionEmployee() { }; // virtual destructor
    
    void setBaseSalary( double ); // set base salary
    double getBaseSalary() const; // return base salary
    
    // keyword virtual signals intent to override
    virtual double earnings() const override; // calculate earnings
    virtual void print() const override; // print object
private:
    double baseSalary; // base salary per week
};

#endif