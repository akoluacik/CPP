#include <iostream>
#include "DivideByZeroException.h"
#include "LengthException.h"
#include "InvalidMemoryAccess.h"


int main(int argc, char const *argv[])
{
    int num, denum;
    std::cin >> num >> denum;
    try
    {
        if(denum == 0)
            throw DivideByZeroException();
        
        double res = static_cast <double> (num) / denum;
        std::cout << "res:" << res << std::endl;
    }
    catch(const std::logic_error& e)
    {
        std::cerr << e.what() << '\n';
    }

    int arr[5] = {1, 2, 3, 4, 5};
    int idx;
    try
    {
        std::cout << "Give an index: ";
        std::cin >> idx;
        
        if(idx > 4)
            throw InvalidMemoryAccess();

        int temp = arr[idx];
        std::cout << temp << std::endl;
    }
    catch(const std::logic_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    int len;

    std::cout << "Give a length to create the array:";
    std::cin >> len;

    try
    {
        if(len > 5)
            throw LengthException();
        // Assume there is a code that creates an array.
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    return 0;
}
