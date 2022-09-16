#if !defined(__BUILDING_H)
#define __BUILDING_H
/**
 * @brief 
 * Changhai Peng,
 * Calculation of a building's life cycle carbon emissions based on Ecotect and building information modeling,
 * Journal of Cleaner Production,
 * Volume 112, Part 1,
 * 2016,
 * Pages 453-465,
 * ISSN 0959-6526,
 * https://doi.org/10.1016/j.jclepro.2015.08.078.
 * (https://www.sciencedirect.com/science/article/pii/S0959652615011695)
 * 
 */

#include "CarbonFootprint.h"

class Building : public CarbonFootprint
{
private:
    // Both AD and EF depends on the industry and region,the equipment and technology used 
    // and type of fuel used
    double AD; // the level of activity
    double EF; // the emission factor
public:
    Building(double AD, double EF);
    ~Building() {}

    double getADValue() const;
    double getEFValue() const;

    virtual double getCarbonFootprint() const override;
};

#endif // __BUILDING_H
