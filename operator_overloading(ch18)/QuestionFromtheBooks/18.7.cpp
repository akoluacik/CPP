#include <iostream>
#include <stdexcept>
#include "array.h"

int main(int argc, char const *argv[])
{
    //array arr2(2,3);
    //std::cin >> arr2;
    
    array arr2{{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
    
    std::cout.precision(2);
    std::cout << arr2;
    
    array arr(arr2);

    std::cout << arr;
    arr(0,1) = 3;
    std::cout << arr;

    array arr3(2);
    std::cout << "Enter 12 numbers:";
    std::cin >> arr3;
    std::cout << arr3;

    array arr4 = arr3;
    std::cout << arr4;

    std::cout << "arr4 == arr3 = " << (arr4 == arr3) << std::endl;
    std::cout << "arr4 != arr3 = " << (arr4 != arr3) << std::endl;
    

    std::cout << "arr4 != arr = " << (arr4 != arr) << std::endl;
    std::cout << "arr4 == arr = " << (arr4 == arr) << std::endl;

    return 0;
}
