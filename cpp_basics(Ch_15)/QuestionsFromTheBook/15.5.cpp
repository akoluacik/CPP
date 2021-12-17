#include <iostream>

inline double rectArea(double w, double l)
{
    return w * l;
}

int main()
{
    double w, l;
    std::cout << "Enter width and length: ";
    std::cin >> w >> l;

    std::cout << "Area of the rectangle is: " << rectArea(w, l) << std::endl;
    
}