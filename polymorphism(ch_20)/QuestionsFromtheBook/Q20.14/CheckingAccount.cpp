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
    Account::credit(amount - feePerTranscation);
}

void CheckingAccount::debit( double amount ) {
    Account::debit(amount + feePerTranscation);
}
