## Chapter 17 - Classes: A Deeper Look; Throwing Exceptions

- Q17.14 : Create a class HugeInteger that uses a 40-element array of digits to store integers as large as 40 digits each. Provide member functions input ,  output , add and subtract . For comparing HugeInteger objects, provide functions isEqualTo , isNotEqualTo , isGreaterThan , isLessThan ,  isGreaterThanOrEqualTo and isLessThanOrEqualTo —each of these is a “predicate” function that simply returns true if the relationship holds between the two  HugeInteger s and re-turns false if the relationship does not hold. Also, provide a predicate function isZero . If you feel ambitious, provide member  functions multiply , divide and modulus .

    - Related solutions are 17.14.cpp as main program, HugeInteger.h is the definition of the class, and HugeInteger.cpp contains the body of the methods.  
    HugeIntegerUtility.cpp contains helper functions which are not attributes of HugeInteger but helps to solve.

- Q17.15 : Create a class TicTacToe that will enable you to write a complete program to play the game of tic-tac-toe. The class contains as private data a 3-by-3 two-dimensional array of integers. The constructor should initialize the empty board to all zeros. Allow two human players. Wherever the first 
player moves, place a 1 in the specified square. Place a 2 wherever the second player moves. Each move must be to an empty square. After each move, 
determine whether the game has been won or is a draw. 

    - Related solution files are 17.15.cpp as main program, TicTacToe.cpp and TicTacToe.h. 