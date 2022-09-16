#include <iostream>
#include <vector>
#include <typeinfo>
#include <iomanip>

#include "Package.h"
#include "OvernightPackage.h"
#include "TwoDayPackage.h"

int main(int argc, char const *argv[])
{
    double newFeePerOunce = 10, flatFee = 16, totalCost = 0.00;
    std::cout << std::fixed << std::setprecision( 2 );
    std::vector < Package * > packages(6);
    packages[0] = new OvernightPackage("Bernadine O Donovan", "4002 Feathers Hooves Drive", " 3544 Sundown Lane,Texas", "Bethpage", "New York", "11714", "78640", 0.5, 10, 5);
    packages[1] = new TwoDayPackage("Edwin B Harman", "212 Fittro Street", "159 Dogwood Road,Phoenix", "Success", "Arkansas", "72470", "85034", 32.7, 20, 10);
    packages[2] = new OvernightPackage("Bernadine O Donovan", "4002 Feathers Hooves Drive", " 3544 Sundown Lane,Texas", "Bethpage", "New York", "11714", "78640", 0.5, 10, 5);
    packages[3] = new TwoDayPackage("Edwin B Harman", "212 Fittro Street", "159 Dogwood Road,Phoenix", "Success", "Arkansas", "72470", "85034", 32.7, 20, 10);
    packages[4] = new OvernightPackage("Bernadine O Donovan", "4002 Feathers Hooves Drive", " 3544 Sundown Lane,Texas", "Bethpage", "New York", "11714", "78640", 0.5, 10, 5);
    packages[5] = new TwoDayPackage("Edwin B Harman", "212 Fittro Street", "159 Dogwood Road,Phoenix", "Success", "Arkansas", "72470", "85034", 32.7, 20, 10);
    
    for (Package *packagePtr : packages) {
        packagePtr->print();
        std::cout << std::endl;
        
        OvernightPackage *derivedPtr = dynamic_cast < OvernightPackage* > (packagePtr);

        if(derivedPtr != NULL) {
            totalCost += derivedPtr->calculateCost();
            std::cout << "Old cost: $" << derivedPtr->calculateCost() << std::endl;
            derivedPtr->setFeePerOunce(newFeePerOunce);
            std::cout << "New cost: $" << derivedPtr->calculateCost() << std::endl << std::endl;
            newFeePerOunce += 5;
        } else {
            TwoDayPackage *derivedPtr2 = dynamic_cast < TwoDayPackage* > (packagePtr);
            if (derivedPtr2 != NULL) {
                totalCost += derivedPtr2->calculateCost();
                std::cout << "Old cost: $" << derivedPtr2->calculateCost() << std::endl;
                derivedPtr2->setFlat_fee(flatFee);
                std::cout << "New cost: $" << derivedPtr2->calculateCost() << std::endl << std::endl;
                flatFee += 8;
            }
        }
    }
    
    std::cout << "Total cost for " << packages.size() << " packages is: $" << totalCost << std::endl;


    return 0;
}
