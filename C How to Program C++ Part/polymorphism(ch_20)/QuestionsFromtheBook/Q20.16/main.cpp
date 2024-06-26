#include <iostream>
#include "CarbonFootprint.h"
#include "Building.h"
#include "Car.h"
#include "Bicycle.h"
#include <iomanip>
#include <vector>


int main(int argc, char const *argv[])
{
    //double carbonFootprint = 0.00;
    std::cout << std::fixed << std::setprecision(2);
    std::vector <CarbonFootprint*> things(3);
    
    things[0] = new Building(10.0, 15.0);
    things[1] = new Car(18365.4, 2016);
    things[2] = new Bicycle(3864.44);

    for(CarbonFootprint* ptr : things) {
        //carbonFootprint = ptr->getCarbonFootprint();
        Building* bPtr = dynamic_cast <Building*>(ptr);
        if(bPtr != NULL ) {
            std::cout << "AD Value: " << bPtr->getADValue();
            std::cout << "\nEF Value: " << bPtr->getEFValue();
            std::cout << " \nCarbon emmission: " << bPtr->getCarbonFootprint() << std::endl;
        } else {
            Car* cPtr = dynamic_cast <Car*>(ptr);
            if(cPtr != NULL) {
                std::cout << "Mileage: " << cPtr->getMileage();
                std::cout << "\nEF Value: " << cPtr->getMpl();
                std::cout << "\nYear: " << cPtr->getYear();
                std::cout << "\nCarbon emmission: " << cPtr->getCarbonFootprint() << std::endl;
            } else {
                Bicycle *bcPtr = dynamic_cast <Bicycle*>(ptr);
                if(bcPtr) {
                    std::cout << "Distance: " << bcPtr->getDistance();
                    std::cout << "Carbon Emmision: " << bcPtr->getCarbonFootprint() << std::endl;
                }
            }
        }
    }
    
    return 0;
}
