#include "my_cmath.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    complex_number cn, cn2, cn3;
    complex_number cn4 = {1,2};
    complex_number cn6 = cn4;
    std::cin >> cn >> cn2;
    std::cout << "cn: " << cn << "cn2: " << cn2 << "cn4: " << cn4 << "cn6:" << cn6 <<std::endl;
    cn3 = cn * cn2;
    std::cout << "cn3 = (cn * cn2) = " << cn3;
    
    complex_number cn5(cn3);
    std::cout << "cn == cn2 => " << (cn == cn2) << " cn2 == cn3 => " << (cn2 == cn3) << " cn3 != cn4 => " << (cn3 != cn4) << " cn3 == cn5 => " << (cn3 == cn5) << " cn4 != cn5 => " << (cn4 != cn5) << std::endl;

    std::cout << "cn3 + cn2 = " << (cn3 + cn2);
    //std::cout << (cn3 / cn2);

    return 0;
}
