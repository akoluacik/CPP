#include <iostream>
#include <cmath>

#define PI 3.14159

inline double sphereVolume(double r)
{
    return (4.0/3.0) * PI * pow(r, 3);
}

int main()
{
    double r;
    std::cout << "Input the radius of your sphere: ";
    std::cin >> r;

    std::cout << "\nVolume of the sphere is: " << sphereVolume(r) << std::endl;
}