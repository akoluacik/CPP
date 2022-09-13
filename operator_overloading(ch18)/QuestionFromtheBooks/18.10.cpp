#include <iostream>
#include "rational.h"

int main(int argc, char const *argv[])
{
    rational rat(4,8);
    rational rat2(4,5);
    rational rat3(-4,5);
    rational rat4(4,-5);
    rational rat5 = rat + rat4;
    std::cout << "Enter rat3: ";
    /*std::cin >> rat3; // doesn't work as expected :(*/

    std::cout << "rat: " << rat << "rat2: " << rat2 << "rat3: " << rat3 << "rat4: " << rat4;
    std::cout << "rat5: " << rat5;

    std::cout << "rat + rat2: " << (rat + rat2);
    std::cout << "rat - rat2: " << (rat - rat2);
    std::cout << "rat * rat2: " << (rat * rat2);
    std::cout << "rat / rat2: " << (rat / rat2);

    std::cout << "rat == rat4: " << (rat == rat4) << std::endl;
    std::cout << "rat != rat4: " << (rat != rat4) << std::endl;
    std::cout << "rat > rat4: " << (rat > rat4) << std::endl;
    std::cout << "rat < rat4: " << (rat < rat4) << std::endl;
    std::cout << "rat >= rat4: " << (rat >= rat4) << std::endl;
    std::cout << "rat <= rat4: " << (rat <= rat4) << std::endl;

    return 0;
}
