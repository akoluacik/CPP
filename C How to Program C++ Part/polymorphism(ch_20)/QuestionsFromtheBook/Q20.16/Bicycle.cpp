#include "Bicycle.h"

Bicycle::Bicycle(double distance)
    : distance(distance)
{
    // empty ctor body    
}

double Bicycle::getDistance() const {
    return distance;
}

double Bicycle::getCarbonFootprint() const {
    return distance * 21;
}