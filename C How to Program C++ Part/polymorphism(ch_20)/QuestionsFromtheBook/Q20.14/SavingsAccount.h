#ifndef __SAVINGS_ACCOUNT_H
#define __SAVINGS_ACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account
{
private:
    double interestRate; // percentage
public:
    SavingsAccount( double, double );
    virtual ~SavingsAccount() {}
    virtual void credit( double ); // deposit money
    virtual void debit( double ); // withdraw money
    double calculateInterest();

    void setInterestRate( double );
    double getInterestRate() const;

};

#endif