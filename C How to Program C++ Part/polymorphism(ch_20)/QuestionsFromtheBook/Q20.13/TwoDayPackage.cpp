#include "TwoDayPackage.h"
#include "Package.h"
#include <iomanip>
#include <iostream>

TwoDayPackage::TwoDayPackage( std::string name, std::string senderAddress, 
                std::string recipientAddress, std::string city, 
                std::string state, std::string senderZipCode, 
                std::string recipientZipCode,
                double _weight, double _costPerOunce,
                double _flat_fee )
    : Package( name, senderAddress, recipientAddress, city, state, senderZipCode, recipientZipCode,
               _weight, _costPerOunce )
{
    setFlat_fee(_flat_fee);
}

double TwoDayPackage::calculateCost() const {
    return Package::calculateCost() + flat_fee;
}

void TwoDayPackage::setFlat_fee( double _flat_fee ) {
    if( _flat_fee <= 0.00) {
        throw std::invalid_argument("Flat fee must be > 0.00");
    } else {
        flat_fee = _flat_fee;
    }
}

double TwoDayPackage::getFlat_fee() const {
    return flat_fee;
}

void TwoDayPackage::print() const {
    Package::print();
    std::cout << "Cost            : " << calculateCost() << std::endl;
}