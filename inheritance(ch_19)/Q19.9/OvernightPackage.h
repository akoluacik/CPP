#ifndef __OVERNIGHT_PACKAGE_H
#define __OVERNIGHT_PACKAGE_H

#include "Package.h"
#include <string>

class OvernightPackage : Package
{
private:
    double feePerOunce;
public:
    OvernightPackage( std::string, std::string, std::string, 
                      std::string, std::string, std::string,
                      double, double, double );
    void setFeePerOunce( double _feePerOunce ); 
    double getFeePerOunce() const;
    double calculateCost() const;
    void print() const;
};

#endif