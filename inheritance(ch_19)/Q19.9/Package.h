#ifndef __PACKAGE_H
#define __PACKAGE_H

#include <string>

class Package
{
private:
    std::string name;
    std::string address;
    std::string city;
    std::string state;
    std::string senderZipCode;
    std::string recipientZipCode;
    double weight; // in ounce
    double costPerOunce;
public:
    Package( std::string, std::string, std::string, std::string, std::string, std::string,
                double, double );
    
    void setAddress( std::string& );
    std::string getAddress() const;

    void setName( std::string& );
    std::string getName() const;

    void setCity( std::string& );
    std::string getCity() const;

    void setState( std::string& );
    std::string getState() const;

    void setSenderZipCode( std::string& );
    std::string getSenderZipCode() const;

    void setRecipientZipCode( std::string& );
    std::string getRecipientZipCode() const;

    void setWeight( double );
    double getWeight() const;

    void setCostPerOunce( double );
    double getCostPerOunce() const;

    double calculateCost() const;

    void print() const;

};

#endif