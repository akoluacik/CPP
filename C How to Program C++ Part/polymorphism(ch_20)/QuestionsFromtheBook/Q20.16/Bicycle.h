#if !defined(__BICYCLE_H)
#define __BICYCLE_H

#include "CarbonFootprint.h"

class Bicycle : public CarbonFootprint
{
private:
    double distance; // in mile
public:
    Bicycle(double distance);
    virtual ~Bicycle() {}
    
    double getDistance() const;
    
    virtual double getCarbonFootprint() const override;

};

#endif // __BICYCLE_H
