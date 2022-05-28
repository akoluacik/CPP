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

- Q17.23: (Card Shuffling and Dealing) Create a program to shuffle and deal a deck of cards. The
program should consist of class Card , class DeckOfCards and a driver program. Class Card should
provide:

    a) Data members face and suit of type int .

    b) A constructor that receives two int s representing the face and suit and uses them to ini-
    tialize the data members.
    
    c) Two static array s of string s representing the faces and suits.
    
    d) A toString function that returns the Card as a string in the form “face of suit.” You
    can use the + operator to concatenate string s.
    
    Class DeckOfCards should contain:
    
    a) An array of Card s named deck to store the Cards.
    
    b) An integer currentCard representing the next card to deal.
    
    c) A default constructor that initializes the Cards in the deck.
    
    d) A shuffle function that shuffles the Card s in the deck. The shuffle algorithm should iterate through the array of Cards. For each Card, randomly select another Card in the deck and swap the two Cards.

    e) A dealCard function that returns the next Card object from the deck.
    
    f) A moreCards function that returns a bool value indicating whether there are more Cards to deal.

    The driver program should create a DeckOfCards object, shuffle the cards, then deal the 52 cards.

- Q17.24 (Card Shuffling and Dealing) Modify the program you developed in Exercise 17.23 so that it deals a five-card poker hand. Then write functions to accomplish each of the following:

    a) Determine whether the hand contains a pair.
    
    b) Determine whether the hand contains two pairs.
    
    c) Determine whether the hand contains three of a 
    kind (e.g., three jacks).
    
    d) Determine whether the hand contains four of a 
    kind (e.g., four aces).
    
    e) Determine whether the hand contains a flush (i.e., all five cards of the same suit).
    
    f) Determine whether the hand contains a straight (i.e., five cards of consecutive face values).

- Q.17.25 (Project: Card Shuffling and Dealing) Use the functions from Exercise 17.24 to write a program that deals two five-card poker hands, evaluates each hand and determines which is the better hand.
    - Related solution files for Q17.23, Q17.24 and Q17.25 are 17.23.cpp(main program), Card.cpp and Card.h; DeckOfCards.cpp and DeckOfCards.h; Hand.cpp and Hand.h.