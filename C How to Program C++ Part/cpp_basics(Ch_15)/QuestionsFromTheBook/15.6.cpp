#include <iostream>

double multiplyByValue(double);
void multiplyByReference(double &);

int main()
{
    double number;
    
    std::cout << "Enter your number: ";
    std::cin >> number;
    
    std::cout << "(multiplyByValue)number * number = " << multiplyByValue(number) << std::endl;
    multiplyByReference(number);
    std::cout << "(multiplyByReference)number * number = " << number << std::endl;
    
}

double multiplyByValue(double number)
{
    return number * number;
}

void multiplyByReference(double &number)
{
    number *= number;
}