#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

void outputLine( int account, const char* const name, double balance);

int main(int argc, char *argv[]) {
    
    // Write a statement that opens file "oldmast.dat" for input; use ifstream object inOldMaster.
    std::ifstream inOldMaster("oldmast.dat", std::ios::in);

    if( !inOldMaster ) {
        std::cerr << "\"oldmast.dat\" file could not be opened!";
        exit(EXIT_FAILURE);
    }

    // Write a statement that opens file "transmast.dat" for input; use ifstream object inTransaction.
    std::ifstream inTransaction("trans.dat", std::ios::in);

    if( !inTransaction ) {
        std::cerr << "\"trans.dat\" file could not be opened!";
        exit(EXIT_FAILURE);
    }
        
    // Write a statement that opens file "newmast.dat" for output; use ofstream object outNewMaster.
    std::ofstream outNewMaster("newmast.dat", std::ios::out);

    if( !outNewMaster ) {
        std::cerr << "\"newmast.dat\" File could not be opened!";
        exit(EXIT_FAILURE);
    }
    
    // Write a statement that reads a record from file "oldmast.dat". 
    // The record consists of integer accountNumber, string name and floating-point currentBalance; 
    // use ifsteram object inOldMaster
    int accountNumber, accountNum;
    //char first_name[30], last_name[30], fullName[60];
    std::string first_name, last_name, fullName;
    double currentBalance, dollarAmount;

    // read the oldMast.dat file
    while (inOldMaster >> accountNumber >> first_name >> last_name >> currentBalance) {
        fullName = first_name + " " + last_name;
        std::cout << accountNumber << " " << fullName << " " << currentBalance << std::endl;
        // read the trans.dat file
        while (inTransaction >> accountNum >> dollarAmount) {
            // if match exists
            if(accountNumber == accountNum) {
                currentBalance += dollarAmount; // update the current balance
            } else {
                std::cout << "Unmatched transaction record for account number " << accountNum << std::endl;
            }
        }
        
        // write the new records to the newmast.dat file
        outNewMaster << accountNumber << ' ' << fullName << ' ' << currentBalance << std::endl;
    }

    return 0;
}

// display signle record from file
void outputLine( int account, const std::string name, double balance) {
    std::cout << std::left << std::setw(10) << account << std::setw(13) << name
              << std::setw(7) << std::setprecision(2) << std::right << balance << std::endl;
}