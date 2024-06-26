#include <iostream>
#include "polynom_utils.h"

int main(int argc, char const *argv[])
{
    polynom pol1(6);
    polynom pol2(6);

    std::cin >> pol1 >> pol2;
    std::cout << pol1 << std::endl << std::endl << pol2;
    polynom pol3 = pol1 + pol2;
    std::cout <<"\n\nres(in main):" << "pol1 + pol2 = " << pol3;

    /*for (size_t i = 0, idx = 0; i < 12; i++)
    {
        if (i%2 == 0)
        {
            std::cout << pol3.getCoeffTerm(idx);
        } else {
            if(pol3.getExpTerm(idx) != 0) {
                std::cout << "x^" << pol3.getExpTerm(idx);
            }
            if(i != 11 ) {
                std::cout << " + ";
            } else {
                std::cout << "";
            }
            ++idx;
        }
        
    }*/
    

    return 0;
}
