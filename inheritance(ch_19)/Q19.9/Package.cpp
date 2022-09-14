#include "Package.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>

Package::Package( std::string name, std::string address, std::string city, 
                  std::string state, std::string senderZipCode, 
                  std::string recipientZipCode,
                  double _weight, double _costPerOunce)
        :name(name), address(address), city(city),
         state(state), senderZipCode(senderZipCode),
         recipientZipCode(recipientZipCode)
{
    setWeight(_weight);
    setCostPerOunce(_costPerOunce);
}


void Package::setAddress( std::string& address) {
    this->address = address;
}
std::string Package::getAddress() const {
    return address;
}

void Package::setName( std::string& name) {
    this->name = name;
}
std::string Package::getName() const {
    return name;
}

void Package::setCity( std::string& city) {
    this->city = city;
}
std::string Package::getCity() const {
    return city;
}

void Package::setState( std::string& state) {
    this->state = state;
}
std::string Package::getState() const {
    return state;
}

void Package::setSenderZipCode( std::string& senderZipCode) {
    this->senderZipCode = senderZipCode;
}

std::string Package::getSenderZipCode() const {
    return senderZipCode;
}

void Package::setRecipientZipCode( std::string& recipientZipCode) {
    this->recipientZipCode = recipientZipCode;
}
std::string Package::getRecipientZipCode() const {
    return recipientZipCode;
}

void Package::setWeight( double _weight) {

    if (_weight <= 0.00) {
        throw std::invalid_argument( "Weight must be > 0.00");
    } else {
        weight = _weight;
    }
}
double Package::getWeight() const  {
    return weight;
}

void Package::setCostPerOunce( double _costPerOunce) {
    
    if (_costPerOunce <= 0.00) {  
        throw std::invalid_argument("Cost per Ounce must be > 0.00");
    } else {
        costPerOunce = _costPerOunce;
    }
}
double Package::getCostPerOunce() const {
    return costPerOunce;
}

double Package::calculateCost() const {
    return costPerOunce * weight;
}

void Package::print() const {
    std::cout << "Name            : " << name << std::endl
              << "Address         : " << address << std::endl
              << "City            : " << city << std::endl
              << "State           : " << state << std::endl
              << "Sender Zip Code : " << senderZipCode << std::endl
              << "Receipt Zip Code: " << recipientZipCode << std::endl
              << "Weight(Ounce)   : " << weight << std::endl;
}