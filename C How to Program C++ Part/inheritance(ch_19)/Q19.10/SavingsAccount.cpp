#include "SavingsAccount.h"
#include <iostream>
#include <stdexcept>

SavingsAccount::SavingsAccount( double balance, double amountOfInterest )
    : Account(balance)
{
    setInterestRate(amountOfInterest);
}

void SavingsAccount::setInterestRate( double amountOfInterest) {
    if(amountOfInterest <= 0 || amountOfInterest > 1) {
        throw std::invalid_argument( "Interest rate must 0< interest rate <= 1!");
    } else {
        interestRate = amountOfInterest;
    }
}

double SavingsAccount::getInterestRate() const {
    return interestRate;
}

double SavingsAccount::calculateInterest() {
    return interestRate * Account::getBalance();
}