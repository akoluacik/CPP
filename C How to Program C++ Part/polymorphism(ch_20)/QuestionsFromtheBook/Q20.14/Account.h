#ifndef __ACCOUNT_H
#define __ACCOUNT_H

class Account
{
private:
    double balance;
public:
    Account(double);
    virtual ~Account() {};
    void setBalance( double );
    double getBalance() const;
    virtual void credit( double ); // deposit money
    virtual void debit( double ); // withdraw money
};

#endif