#if !defined(__CAR_H)
#define __CAR_H

#include "CarbonFootprint.h"

class Car : public CarbonFootprint
{
private:
    double mileage; // distance taken in mile
    double mpl; // miles per litre
    int year; // released year of the car
public:
    Car(double mileage, int year);
    virtual ~Car() {};
    
    virtual double getCarbonFootprint() const override;
    void setMileage( double _mileage );
    void setMpl( int year ); // mpl is assigned according to year of the car.
    void setYear(int _year);

    double getMileage() const;
    double getMpl() const;
    int getYear() const;

};

#endif // __CAR_H
