#ifndef __CARBON_FOOTPRINT_H
#define __CARBON_FOOTPRINT_H

class CarbonFootprint
{
public:
    CarbonFootprint();
    virtual ~CarbonFootprint() {}
    virtual double getCarbonFootprint() const = 0;
};

#endif