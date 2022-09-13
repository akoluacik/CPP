#include "emergencyResponse.h"
#include <ctime>
#include <iostream>

emergencyResponse::emergencyResponse(){
    dummy = 1;
}

emergencyResponse::emergencyResponse(std::string fullName, std::string phoneNumber, std::string location, emergencyTypedef emergencyType, responseTypedef response) {
    
    setFullName(fullName);
    setPhoneNumber(phoneNumber);
    setLocation(location);
    setEmergencyType(emergencyType);
    setDate();
}

/*emergencyResponse::~emergencyResponse() {
    delete date;
    std::cout << "Object is destroyed!" << std::endl;
}*/

void emergencyResponse::setFullName(std::string fullName) {
    this->fullName = fullName;
}

void emergencyResponse::setPhoneNumber(std::string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void emergencyResponse::setLocation(std::string location) {
    this->location = location;
}

void emergencyResponse::setEmergencyType(emergencyTypedef emergencyType) {
    this->emergencyType = emergencyType;
}

void emergencyResponse::setDate() {
    
    time_t date = time(0);
    this->date = ctime(&date);
}

void emergencyResponse::setResponse(responseTypedef response) {
    this->response = response;
}



std::string emergencyResponse::getFullName() const {
    return fullName;
}

std::string emergencyResponse::getphoneNumber() const {
    return phoneNumber;
}

std::string emergencyResponse::getLocation() const {
    return location;
}

emergencyTypedef emergencyResponse::getEmergencyType() const {
    return emergencyType;
}

char* emergencyResponse::getDate() const {
    return date;
}

responseTypedef emergencyResponse::getResponse() const {
    return this->response;
}