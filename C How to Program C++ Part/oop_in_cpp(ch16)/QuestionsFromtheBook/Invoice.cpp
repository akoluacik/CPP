#include <iostream>
#include "Invoice.h"

Invoice::Invoice(std::string _partNumber, std::string _description
, int _amount, int _price)
    :partNumber(_partNumber)
    ,description(_description)
    ,amount(_amount)
    ,price(_price)
{
    // empty constructor body
}

void Invoice::setPartNumber(std::string _partNumber){ partNumber = _partNumber; }
void Invoice::setDescription(std::string _description){ description = _description; }
void Invoice::setAmount(int _amount){ amount = _amount; }
void Invoice::setPrice(int _price){ price = _price; }

std::string Invoice::getPartNumber(){ return partNumber; }
std::string Invoice::getDescription(){ return description; }
int Invoice::getAmount(){ return amount; }
int Invoice::getPrice() { return price; }
int Invoice::getInvoiceAmount(){ 
    int result = amount * price;
    return result > 0 ? result : 0;    
}
