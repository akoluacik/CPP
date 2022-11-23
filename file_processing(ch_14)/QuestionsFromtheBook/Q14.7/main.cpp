#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

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
    std::string first_name, last_name, fullName;
    double currentBalance, dollarAmount;
    bool found = false;

    // read the oldMast.dat file
    while (inOldMaster >> accountNumber >> first_name >> last_name >> currentBalance) {
        fullName = first_name + " " + last_name;
        found = true;
        //std::cout << accountNumber << " " << fullName << " " << currentBalance << std::endl;
        // read the trans.dat file
        while (inTransaction >> accountNum >> dollarAmount) {
            // if match exists
            if(accountNumber == accountNum) {
                currentBalance += dollarAmount; // update the current balance
                found = true;
                break;
            } 

            // this is necessary if accountNum doesn't appear in oldmast.dat file because
            // cursor of inTransaction reaches the end of the file. To keep continue to read
            // we need to get re-positioned it from beginning. But this time, it cannot handle
            // the transactions if accountNum appears multiple times.
            if(inTransaction.eof()) {
                inTransaction.seekg(std::ios::beg);
                break;
            }
        }
        if(!found) {
            std::cout << "Unmatched transaction record for # " << accountNumber << std::endl;
        }
        // write the new records to the newmast.dat file
        outNewMaster << accountNumber << ' ' << fullName << ' ' << currentBalance << std::endl;
    }

    return 0;
}