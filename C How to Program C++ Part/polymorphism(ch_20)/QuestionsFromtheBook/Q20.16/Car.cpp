#include "Car.h"

Car::Car(double mileage, int year) 
    : mileage(mileage),
      year(year)
{
    setMpl(year);
}

void Car::setMileage( double _mileage ) {
    mileage = _mileage;
}

// the values are made up, not reflect the real values
void Car::setMpl( int year ){
    if( year < 2007 ) {
        mpl = 8.7;
    } else if( year >= 2007 && year <= 2012 ) {
        mpl = 11.9;
    } else if( year > 2012 && year <= 2015 ) {
        mpl = 20.6;
    } else if( year > 2015 && year <= 2019 ) {
        mpl = 35.3;
    } else {
        mpl = 40.6;
    }
}

void Car::setYear(int _year){
    year = _year;
}


double Car::getCarbonFootprint() const {
    double res = mileage / mpl * 2.68;
    return res;
}


double Car::getMileage() const {
    return mileage;
}

double Car::getMpl() const {
    return mpl;
}

int Car::getYear() const {
    return year;
}