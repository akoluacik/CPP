#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Package pck("John Doe", "1125 Collins St, Joliet", "Will" ,"Illinois", "60432", "86301", 16.03, 5.54);
    TwoDayPackage tdp("Sylvester M Marrero", "237 Walnut Street", "Vicksburg", "Mississippi", "39180", "06103", 48, 5, 30);
    OvernightPackage onp("Kevin O Winters", "908 Emma Street", "Kaneohe", "Hawaii", "96744", "57075", 98.7, 5.4, 3);

    std::cout << "Package:" << std::endl;
    pck.print();

    std::cout << "\n\nTwoDayPackage:" << std::endl;
    tdp.print();

    std::cout << "\n\nOvernightPackage:" << std::endl;
    onp.print();


    return 0;
}
