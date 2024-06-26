#include <iostream>
#include "HugeInteger.h"

int main()
{

    HugeInteger hui = HugeInteger();

    hui.Input();
    std::cout << "hui1:";
    hui.Output();

    HugeInteger hui2 = HugeInteger();
    hui2.Input();
    std::cout << "hui2:";
    hui2.Output();

    std::cout << "isEqual ? " << hui.isEqual(hui2) << std::endl;
    std::cout << "isNotEqual ? " << hui.isNotEqual(hui2) << std::endl;
    std::cout << "isGreater ? " << hui.isGreater(hui2) << std::endl;
    std::cout << "isGreaterThanorEqual ? " << hui.isGreaterThanorEqualTo( hui2 ) << std::endl;
    std::cout << "isLess ? " << hui.isLessThan( hui2 ) << std::endl;
    std::cout << "isLessThanorEqual ? " << hui.isLessThanorEqualTo( hui2 ) << std::endl;

    hui.Add( hui2 );
    hui.Substract( hui2 );
    
    return 0;
}