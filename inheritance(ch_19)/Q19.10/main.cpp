#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

int main(int argc, char const *argv[])
{
    Account acc( 1000 );
    acc.debit(300);
    std::cout << "NEw Balance: " << acc.getBalance() << std::endl;

    SavingsAccount sa(2000, 0.4);
    sa.calculateInterest();
    std::cout << "Earning interest rate: " << sa.calculateInterest() << std::endl;

    CheckingAccount ca(3000, 1.85);
    ca.credit(2000);
    std::cout << "New Balance: " << ca.getBalance() << std::endl;
    ca.debit(4500);
    std::cout << "New Balance: " << ca.getBalance() << std::endl;
    return 0;
}
