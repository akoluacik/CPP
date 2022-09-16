#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>


#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"


int main(int argc, char const *argv[])
{
    std::cout << std::fixed << std::setprecision(2);
    std::vector <Account *> accounts(4);

    accounts[0] = new CheckingAccount(5000, 1.6);
    accounts[1] = new SavingsAccount(5284, 0.84);
    accounts[2] = new CheckingAccount(3750, 1.53);
    accounts[3] = new SavingsAccount(20000, 0.6);

    for(Account* accountPtr : accounts) {
        std::cout << "Old balance: " << accountPtr -> getBalance() << std::endl; 
        accountPtr->debit(3500);
        std::cout << "New Balance: " << accountPtr -> getBalance() << std::endl;

        CheckingAccount* ptr = dynamic_cast < CheckingAccount*> (accountPtr);
        if(ptr != NULL ) {
            ptr->setFee(ptr->getFee() * 2);
            std:: cout << "Old Balance: " << ptr->getBalance() << std::endl;
            ptr->credit(5000);
            std::cout << "New balance: " << ptr->getBalance() << std::endl;
        } else {
            SavingsAccount* ptr = dynamic_cast < SavingsAccount*> (accountPtr);
            ptr->calculateInterest();
            std::cout << "Owed interest is: " << ptr->calculateInterest() << "\nBalance is: " << ptr->getBalance() << std::endl;
            ptr->credit(ptr->calculateInterest());
            std::cout << "New balance: " << ptr->getBalance() << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
