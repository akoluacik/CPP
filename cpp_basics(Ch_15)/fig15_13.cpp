#include <iostream>
#include "maximum.h"
using namespace std;

int main()
{
    int int1, int2, int3;
    cout << "Input three int values: "; cin >> int1 >> int2 >> int3;

    // invoke int version of max
    cout << "The max integeter value is " << maximum(int1, int2, int3);

    double double1, double2, double3;
    cout << "\n\nInput three double values: "; cin >> double1 >> double2 >> double3;
    cout << "The maximum value of double is: " << maximum(double1, double2, double3);
    
    char c1, c2, c3;
    cout << "\n\nInput three characters: "; cin >> c1 >> c2 >> c3;
    cout << "The maximum char value is: " << maximum(c1, c2, c3) << endl;

    /* pow function calls */
    int power;
    float base;
    cout << "Input a base and a power respectively: "; cin >> base >> power;
    cout << base << "^" << power << " = " << pow(base, power) << endl;
    
}