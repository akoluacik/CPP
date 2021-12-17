#include <iostream>

template <class T>
void swap(T &value1, T &value2)
{
    T temp = value1;
    value1 = value2;
    value2 = temp;
}

int main()
{
    int value1, value2;
    
    /* SWAPPING INTEGERS */
    std::cout << "Enter two numbers" << std::endl;
    std::cin >> value1 >> value2;
    std::cout << "Before swapping: " << std::endl;
    std::cout << "value1: " << value1 << " value2: " << value2 << std::endl;

    swap(value1, value2);
    std::cout << "After swapping: " << std::endl;
    std::cout << "value1: " << value1 << " value2: " << value2 << std::endl;

    /* SWAPPING CHARS */
    char c1, c2;
    std::cout << "Enter two characters" << std::endl;
    std::cin >> c1 >> c2;

    std::cout << "Before swapping: " << std::endl;
    std::cout << "c1: " << c1 << " c2: " << c2 << std::endl;

    swap(c1, c2);
    std::cout << "After swapping: " << std::endl;
    std::cout << "c1: " << c1 << " c2: " << c2 << std::endl;

    /* SWAPPING TWO-FLOATING-POINTS */
    float f1, f2;
    std::cout << "Enter two floating-point numbers" << std::endl;
    std::cin >> f1 >> f2;

    std::cout << "Before swapping: " << std::endl;
    std::cout << "f1: " << f1 << " f2: " << f2 << std::endl;

    swap(f1, f2);
    std::cout << "After swapping: " << std::endl;
    std::cout << "f1: " << f1 << " f2: " << f2 << std::endl;
    
}