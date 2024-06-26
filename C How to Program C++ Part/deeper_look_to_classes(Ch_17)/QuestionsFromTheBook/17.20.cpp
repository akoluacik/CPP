#include <iostream>
#include "SavingAccounts.h"

double SavingAccounts::annualInterestRate = 3.0;


int main() {

    SavingAccounts saver1 = SavingAccounts();
    SavingAccounts saver2 = SavingAccounts();

    saver1.setSavingsBalance(2000);
    saver2.setSavingsBalance(3000);

    std::cout << "Balance of Saver1\tBalance of Saver2" << std::endl;

    for (size_t i = 0; i < 4; i++)
    {
        saver1.calculateMonthlyInterestRate();
        saver2.calculateMonthlyInterestRate();
        std::cout << saver1.getSavingsBalance() << "\t\t\t" << saver2.getSavingsBalance() << std::endl;
    }
    
    return 0;
}