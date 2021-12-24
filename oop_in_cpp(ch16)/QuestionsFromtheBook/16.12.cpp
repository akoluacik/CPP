#include <iostream>
#include "Inventory.h"

void purchaseProduct(Inventory &inventory, int amount);
void saleProduct(Inventory &inventory, int amount);

int main()
{
    Inventory inv1 = Inventory("Laptop");
    Inventory inv2 = Inventory("Phone");

    purchaseProduct(inv1, 23);
    saleProduct(inv1, 2);
    
    purchaseProduct(inv2, 13);
    purchaseProduct(inv2, 9);
    saleProduct(inv2, 2);
    
    return 0;
}

void purchaseProduct(Inventory &inventory, int amount)
{
    for (size_t i = 0; i < amount; i++)
    {
        inventory.Purchase(); // purchase that product
    }
    std::cout << inventory.getStock() << std::endl; // print out the stock
}

void saleProduct(Inventory &inventory, int amount)
{
    for (size_t i = 0; i < amount; i++)
    {
        inventory.Sale(); // sell a product
    }
    std::cout << inventory.getStock() << std::endl; // print out the stock
    
}