## Chapter 17 - Classes: A Deeper Look; Throwing Exceptions

- Q17.14 : Create a class HugeInteger that uses a 40-element array of digits to store integers as large as 40 digits each. Provide member functions input ,  output , add and subtract . For comparing HugeInteger objects, provide functions isEqualTo , isNotEqualTo , isGreaterThan , isLessThan ,  isGreaterThanOrEqualTo and isLessThanOrEqualTo —each of these is a “predicate” function that simply returns true if the relationship holds between the two  HugeInteger s and re-turns false if the relationship does not hold. Also, provide a predicate function isZero . If you feel ambitious, provide member  functions multiply , divide and modulus .

    - Related solutions are 17.14.cpp as main program, HugeInteger.h is the definition of the class, and HugeInteger.cpp contains the body of the methods.
    HugeIntegerUtility.cpp contains helper functions which are not attributes of HugeInteger but helps to solve.

- Q17.15 : Create a class TicTacToe that will enable you to write a complete program to play the game of tic-tac-toe. The class contains as private data a 3-by-3 two-dimensional array of integers. The constructor should initialize the empty board to all zeros. Allow two human players. Wherever the first 
player moves, place a 1 in the specified square. Place a 2 wherever the second player moves. Each move must be to an empty square. After each move, 
determine whether the game has been won or is a draw. 

    - Related solution files are 17.15.cpp as main program, TicTacToe.cpp and TicTacToe.h. 

- Q17.19 : Modify class Date in Fig. 17.17 to have the following capabilities:
    a) Output the date in multiple formats such as
    DDD YYYY
    MM/DD/YY
    June 14, 1992
    b) Use overloaded constructors to create Date objects initialized with dates of the formatsin part (a).
    c) Create a Date constructor that reads the system date using the standard library functions of the <ctime> header and sets the Date members. See your compiler’s reference docu-
    mentation or en.cppreference.com/w/cpp/chrono/c for information on the functions in header <ctime> . You might also want to check out C++11’s new chrono library at en.cppreference.com w/cpp/chrono
    
    - Related files for the solution are Date.h, Date.cpp and 17.19.cpp. 
    Note that part will be done asap. In this version, program have three ctor, 
    one use ctime, one takes three and the other takes two parameters.
- Q17.20 : ( SavingsAccount Class) Create a SavingsAccount class. Use a static data member annual-
to store the annual interest rate for each of the savers. Each member of the class con-
tains a private data member savingsBalance indicating the amount the saver currently has on
deposit. Provide member function calculateMonthlyInterest that calculates the monthly interest
by multiplying the savingsBalance by annualInterestRate divided by 12; this interest should be
added to savingsBalance . Provide a static member function modifyInterestRate that sets the
static annualInterestRate to a new value. Write a driver program to test class SavingsAccount . In-
stantiate two different objects of class SavingsAccount , saver1 and saver2 , with balances of
$2000.00 and $3000.00, respectively. Set the annualInterestRate to 3 percent. Then calculate the
monthly interest and print the new balances for each of the savers. Then set the annualInterestRate
to 4 percent, calculate the next month’s interest and print the new balances for each of the savers.

    - Related files 17.20.cpp along with SavingAccounts.h and SavingAccount.cpp.