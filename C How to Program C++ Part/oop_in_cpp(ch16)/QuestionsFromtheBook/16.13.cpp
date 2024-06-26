#include <iostream>
#include "Invoice.h"

int main()
{
    Invoice invoice1 = Invoice("A90684176639", "ASUS FX550VXK I77700HQ GTX950M 8GB 1TB HDD 512GB SSD", 13, 9600);
    std::cout << "Part Number: " << invoice1.getPartNumber() << " Description: " << invoice1.getDescription() << " Amount: " << invoice1.getAmount() << " Price: " << invoice1.getPrice() << std::endl;
    std::cout << "Invoice Amount:" << invoice1.getInvoiceAmount() << std::endl;
    
    return 0;
}