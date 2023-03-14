//
// Created by c on 3/8/23.
//

#include "MinesweeperBoard.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>


MinesweeperBoard::MinesweeperBoard()
{
    width=5;
    height=7;
    board_clear();
    board_debug_field();
    board_debug_field2();
}

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{
    this->width=width;
    this->height=height;
    board_clear();
    board_field_randomize(mode);
    //board_debug_field();
    //board_debug_field();
}

//==============================
//Funkcja wyświetla stan planszy
//==============================
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

//====================================
//Funkcja czyści każde pole na planszy
//====================================
void MinesweeperBoard::board_clear()
{
    for(int row=0; row<height; row++)
    {
        for(int col=0; col<width; col++)
        {
            board[row][col].hasFlag=false;
            board[row][col].hasMine=false;
            board[row][col].isRevealed=false;
        }
    }
}

//========================================
//Funkcja ustawia predefiniowany układ min
//========================================
void MinesweeperBoard::board_debug_field()
{
    board[0][0].hasMine=true;
    board[0][0].hasFlag=false;
    board[0][0].isRevealed=false;

    board[1][1].hasMine=false;
    board[1][1].hasFlag=false;
    board[1][1].isRevealed=true;

    board[0][2].hasMine=true;
    board[0][2].hasFlag=true;
    board[0][2].isRevealed=false;
}

//========================================
//Funkcja ustawia predefiniowany układ min
//========================================
void MinesweeperBoard::board_debug_field2()
{
    for(int row=0; row<height; row++)
    {
        for(int col=0; col<width; col++)
        {
            if(row==0)
            {
                board[row][col].hasMine=true;
            }
            else if(row%2==0 and col==0)
            {
                board[row][col].hasMine=true;
            }
            else if(col==row)
            {
                board[row][col].hasMine=true;
            }
        }
    }
}

//==========================================
//Funkcja randomizuje rozkład min na planszy
//IN: mode - tryb gry, decyduje o mineAmount
//==========================================
void MinesweeperBoard::board_field_randomize(GameMode mode)
{
    int boardSize=width*height;
    int mineAmount;

    switch(mode)
    {
        case EASY:
            mineAmount = std::ceil(boardSize*0.1);
            break;
        case NORMAL:
            mineAmount = std::ceil(boardSize*0.2);
            break;
        case HARD:
            mineAmount = std::ceil(boardSize*0.3);
            break;
        case DEBUG:
            board_debug_field2();
            return;
    }

    std::vector<int> indxList;
    for(int indx=0; indx<boardSize; indx++)
    {
        indxList.push_back(indx);
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (indxList.begin(), indxList.end(), std::default_random_engine(seed));

    int row, col;
    for(int mineNo=0; mineNo<mineAmount; mineNo++)
    {
        row=indxList[mineNo]/width;
        col=indxList[mineNo]%width;
        board[row][col].hasMine=true;
    }
}