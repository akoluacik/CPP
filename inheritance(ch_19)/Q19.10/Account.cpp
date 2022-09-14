#include "Account.h"
#include <stdexcept>
Account::Account( double amount ) {
    setBalance(amount);
}

void Account::setBalance( double amount ) {
    if( amount < 0) {
        throw std::invalid_argument("Initial balance must be >= 0! The balance is equalized to 0.0");
        balance = 0.0;
    } else {
        balance = amount;
    }
}

double Account::getBalance() const {
    return balance;
}

void Account::credit( double amount ) {
    if( amount > 0 ) {
        balance += amount;
    } else {
        throw std::invalid_argument("Amount to be deposit must be > 0");
    }
}

void Account::debit( double amount ) {
    if ( amount <= 0) {
        throw std::invalid_argument("Amount to be withdraw must be > 0. Balance is not changed!");
    } else if( amount > balance ) {
        throw std::invalid_argument("Debit amount exceeded account balance. Balance is not changed!");
    } else {
        balance -= amount;
    }
}
