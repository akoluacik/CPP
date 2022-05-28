#include "SavingAccounts.h"
#include <iostream>


void SavingAccounts::calculateMonthlyInterestRate() {
    savingsBalance = savingsBalance + savingsBalance * annualInterestRate / 12.0;
}

void SavingAccounts::setSavingsBalance(double balance) {
    savingsBalance = balance;
}

double SavingAccounts::getSavingsBalance() const {
    return savingsBalance;
}

// we've told to compiler that this method is static, we no longer need type static here
void SavingAccounts::modifyInterestRate(double rate) {
    annualInterestRate = rate;
}