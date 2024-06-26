// TicTacToe class definition, question 17.15 from C How to Program with Introduction to C++.
// Methods' body will be defined in TicTacToe.cpp

class TicTacToe
{
private:
    int board[3][3] = {0};
    bool isAllFilled() const;
    bool isValid( int x, int y ) const; // checks if given position is valid
    bool CheckRow( int , int ) const;
    bool CheckCol( int, int ) const;
    bool checkDiag( int ) const;
public:
    TicTacToe(/* args */);
    ~TicTacToe();
    void Print() const;
    void FillBoard( int, int, int ); // player, X-Coordinate, Y-Coordinate
    bool WhoWon( int, int, int ) const;
    void Play(); // driver method
};
