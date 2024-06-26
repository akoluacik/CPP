// TicTacToe.cpp

#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe(/* args */)
{
    std::cout << "Object is created" << std::endl;
    Print();
    Play();
}

TicTacToe::~TicTacToe()
{
    std::cout << "Object is destroyed!" << std::endl;
}


void TicTacToe::Print() const
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}

bool TicTacToe::isValid( int x, int y ) const
{
    return (x > 3 || y > 3 || x < 0 || y < 0) ? false : ((board[x][y] != 0) ? false : true); // checks if x and y between 0-3 and given position isn't filled yet.
}

bool TicTacToe::isAllFilled() const
{
    int count = 0;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if ( board[i][j] != 0)
            {
                ++count;
            }
        }
    }
    return count  == 9 ? true : false;
}

bool TicTacToe::CheckRow( int player, int row ) const
{
    int count = 0;
    for (size_t col = 0; col < 3; col++)
    {
        if ( board[row][col] == player)
        {
            ++count;
        }
    }
    std::cout << "count in check row: " << count << std::endl;
    return (count == 3) ? true : false;
}

bool TicTacToe::CheckCol( int player, int col ) const
{
    int count = 0;
    for (size_t row = 0; row < 3; row++)
    {
        if ( board[row][col] == player)
        {
            ++count;
        }
    }
    std::cout << "count in check col: " << count << std::endl;
    return (count == 3) ? true : false;
}

bool TicTacToe::checkDiag( int player) const
{
    int count = 0;
    for (size_t i = 0; i < 3; i++)
    {
        if ( (board[i][i] == player) || (board[i][2-i] == player) )
        {
            ++count;
        }
    }
    std::cout << "count in check diag: " << count << std::endl;
    return (count == 3) ? true : false;
}

void TicTacToe::FillBoard( int player, int x, int y ) { board[x][y] = player; }

bool TicTacToe::WhoWon( int player , int row, int col ) const
{

    if ( CheckRow( player, row ) || CheckCol( player, col ) || checkDiag( player ))
    {
        std::cout << "Player-" << player << " won the game!" << std::endl;
        return true;
    }
    return false;
}

void TicTacToe::Play()
{
    int x, y, player = 0;
    
    while ( !isAllFilled() )
    {
        
        std::cout << "Player - " << player + 1 << " your turn, please give coordinate for 3x3 matrix:";
        std::cin >> x >> y;
        
        while ( !isValid(x, y) )
        {
            std::cout << "[ERROR] Invalid coordinates, please give valid coordinates:";
            std::cin >> x >> y;
        }

        FillBoard( player + 1, x, y );
        Print();
        
        if ( checkDiag(player + 1) || CheckRow( player + 1, x) || CheckCol(player + 1, y) )
        {
            std::cout << "Player - " << player + 1 << " won the game!" << std::endl;
            return;
        }
        player = !player;
    }
    std::cout << "DRAW!" << std::endl;
}