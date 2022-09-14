#ifndef __CHECKING_ACCOUNT_H
#define __CHECKING_ACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account
{
private:
    double feePerTranscation; // percentage
public:
    CheckingAccount( double, double );

    void credit( double ); // deposit money
    void debit( double ); // withdraw money
    
    void setFee( double );
    double getFee() const;
};

#endif