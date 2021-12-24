#include <iostream>
#include "Inventory.h"

Inventory::Inventory(std::string _productName)
    :productName(_productName)
{
    if (stock < 20) std::cout << "Product must have 20 stocks, at least!" << std::endl;
    
}
int Inventory::getStock() const
{
    return stock;
}

void Inventory::Purchase()
{
    ++stock;
}

void Inventory::Sale()
{
    --stock;
}

