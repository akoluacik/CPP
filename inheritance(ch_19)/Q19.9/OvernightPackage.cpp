#include "OvernightPackage.h"
#include "Package.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>
OvernightPackage::OvernightPackage( std::string name, std::string address, std::string city, 
                std::string state, std::string senderZipCode,
                std::string recipientZipCode,
                double _weight, double _costPerOunce,
                double feePerOunce )
    : Package( name, address, city, state, senderZipCode, recipientZipCode,
               _weight, _costPerOunce )
{
    setFeePerOunce(feePerOunce);
}

double OvernightPackage::calculateCost() const {
    return (feePerOunce + Package::getCostPerOunce()) * Package::getWeight();
}

void OvernightPackage::setFeePerOunce( double _feePerOunce ) {
    if( _feePerOunce <= 0.00) {
        throw std::invalid_argument("Fee per Ounce must be > 0.00");
    } else {
        feePerOunce = _feePerOunce;
    }
}

double OvernightPackage::getFeePerOunce() const {
    return feePerOunce;
}

void OvernightPackage::print() const {
    Package::print();
    std::cout << "Cost            : " << calculateCost() << std::endl;
}