#include <iostream>

int number = 7; // Unary scope resolution is needed to access this
int globalNumber = 9; // No need to use Unary scope resolution

int main()
{
    double number = 10.5; // local variable named number

    std::cout << "Local double value of number = " << number << "\nGlobal int value of number = " << ::number << std::endl;
    std::cout << "Global variable globalNumber without Unary Scope = " << globalNumber << std::endl << "globalNumber with Unary scope = " << ::globalNumber << std::endl;

    
    return 0;
}