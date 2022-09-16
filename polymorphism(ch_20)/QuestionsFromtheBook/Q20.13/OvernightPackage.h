#ifndef __OVERNIGHT_PACKAGE_H
#define __OVERNIGHT_PACKAGE_H

#include "Package.h"
#include <string>

class OvernightPackage : public Package
{
private:
    double feePerOunce;
public:
    OvernightPackage( std::string, std::string, std::string, std::string,
                      std::string, std::string, std::string,
                      double, double, double );
    void setFeePerOunce( double _feePerOunce ); 
    double getFeePerOunce() const;
    double calculateCost() const override;
    void print() const;
};

#endif