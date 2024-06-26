#ifndef __ACCOUNT_H
#define __ACCOUNT_H

class Account
{
private:
    double balance;
public:
    Account(double);
    
    void setBalance( double );
    double getBalance() const;
    void credit( double ); // deposit money
    void debit( double ); // withdraw money
};

#endif