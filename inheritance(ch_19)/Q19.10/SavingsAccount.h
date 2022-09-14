#ifndef __SAVINGS_ACCOUNT_H
#define __SAVINGS_ACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account
{
private:
    double interestRate; // percentage
public:
    SavingsAccount( double, double );

    void credit( double ); // deposit money
    void debit( double ); // withdraw money
    double calculateInterest();

    void setInterestRate( double );
    double getInterestRate() const;

};

#endif