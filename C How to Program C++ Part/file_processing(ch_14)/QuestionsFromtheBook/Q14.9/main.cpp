#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

void outputLine( int account, const std::string name, double balance);

int main(int argc, char *argv[]) {
    
    // AFAIK, we need creat either ifstream or fstream object to retrieve record
    // please correct me if I'm wrong.
    std::ifstream inOutMaster("newmast.dat", std::ios::in);
    int accountNumber;
    std::string first_name, last_name, fullName;
    double currentBalance, dollarAmount;

    while (inOutMaster >> accountNumber >> first_name >> last_name >> currentBalance) {
        fullName = first_name + " " + last_name;
        outputLine(accountNumber, fullName, currentBalance);
    }
    
    return 0;
}

void outputLine( int account, const std::string name, double balance) {
    std::cout << std::left << std::setw(10) << account << std::setw(13) << name
              << std::setw(7) << std::setprecision(2) << std::right << balance << std::endl;
}