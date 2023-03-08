//
// Created by c on 3/8/23.
//

#include "MinesweeperBoard.h"
#include <iostream>


MinesweeperBoard::MinesweeperBoard()
{
    width=5;
    height=7;
    board_init();
    board_debug_field();
}

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{
    
}

void MinesweeperBoard::debug_display() const
{
    for(int row=0; row<height; row++)
    {
        for (int col=0; col<width; col++)
        {
            std::cout << "[";
            if(board[row][col].hasMine)
            {std::cout << "M";}
            else
            {std::cout << ".";}

            if(board[row][col].isRevealed)
            {std::cout << "o";}
            else
            {std::cout << ".";}

            if(board[row][col].hasFlag)
            {std::cout << "f";}
            else
            {std::cout << ".";}
            std::cout << "]";

        }
        std::cout << std::endl;
    }
}

void MinesweeperBoard::board_init(int width, int height)
{
    for(int row=0; row<height; row++)
    {
        for(int col=0; col<width; col++)
        {
            board[row][col].hasFlag=0;
            board[row][col].hasMine=0;
            board[row][col].isRevealed=0;
        }
    }
}

void MinesweeperBoard::board_debug_field()
{
    board[0][0].hasMine=1;
    board[0][0].hasFlag=0;
    board[0][0].isRevealed=0;

    board[1][1].hasMine=0;
    board[1][1].hasFlag=0;
    board[1][1].isRevealed=1;

    board[0][2].hasMine=1;
    board[0][2].hasFlag=1;
    board[0][2].isRevealed=0;
}