#include "Building.h"

Building::Building(double AD, double EF ) 
    :AD(AD), EF(EF)
{
    //empty ctor body
}

double Building::getADValue() const {
    return AD;
}

double Building::getEFValue() const {
    return EF;
}

double Building::getCarbonFootprint() const {
    return AD * EF;
}