#include "CheckingAccount.h"
#include "Account.h"
#include <stdexcept>

CheckingAccount::CheckingAccount( double amount, double fee ) 
    :Account(amount)
{
    setFee(fee);
}

void CheckingAccount::setFee( double _fee) {
    if(_fee >= 0 )
        feePerTranscation = _fee;
}

double CheckingAccount::getFee() const {
    return feePerTranscation;
}

void CheckingAccount::credit( double amount ) {
    double newBalance;
    if( amount > 0 ) {
        newBalance = amount + Account::getBalance() - feePerTranscation;
        Account::setBalance(newBalance);
    } else {
        throw std::invalid_argument("Amount to be deposit must be > 0");
    }
}

void CheckingAccount::debit( double amount ) {
    double newBalance;
    if ( amount <= 0) {
        throw std::invalid_argument("Amount to be withdraw must be > 0. Balance is not changed!");
    } else if( amount > Account::getBalance() ) {
        throw std::invalid_argument("Debit amount exceeded account balance. Balance is not changed!");
    } else {
        newBalance = Account::getBalance() - amount - feePerTranscation;
        Account::setBalance(newBalance);
    }
}
