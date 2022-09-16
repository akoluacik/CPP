#ifndef __CHECKING_ACCOUNT_H
#define __CHECKING_ACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account
{
private:
    double feePerTranscation; // percentage
public:
    CheckingAccount( double, double );
    virtual ~CheckingAccount() {}
    virtual void credit( double ) override; // deposit money
    virtual void debit( double ) override; // withdraw money
    
    void setFee( double );
    double getFee() const;
};

#endif