#ifndef __TWO_DAY_PACKAGE_H
#define __TWO_DAY_PACKAGE_H

#include "Package.h"
#include <stdexcept>
class TwoDayPackage : public Package
{
private:
    double flat_fee;
public:
    TwoDayPackage( std::string, std::string, std::string, 
                   std::string, std::string, std::string,
                   double, double, double );

    void setFlat_fee( double _flat_fee ); 
    double getFlat_fee() const;
    double calculateCost() const;
    void print() const;
};

#endif