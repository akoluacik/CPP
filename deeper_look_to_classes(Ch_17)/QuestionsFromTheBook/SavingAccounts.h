#ifndef SAVINGACCOUNTS_H
#define SAVINGACCOUNTS_H


class SavingAccounts
{
private:
    static double annualInterestRate;
    double savingsBalance;

public:
    void calculateMonthlyInterestRate();
    static void modifyInterestRate( double );
    void setSavingsBalance( double );
    double getSavingsBalance() const;
};

#endif