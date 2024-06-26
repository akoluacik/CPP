#include <iostream>
// Addition program that displays sum of two numbers

int main(){
    std::cout << "Enter a number : "; // prompt user fır data
    int number1;
    std::cin >> number1;

    std::cout << "Enter second integer: ";
    int number2;
    std::cin >> number2;
    
    int sum = number1 + number2;
    std::cout << "Sum is " << sum << std::endl;
}
