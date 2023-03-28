//
// Created by kubab on 25.03.2023.
//
#include <iostream>
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"

MSBoardTextView::MSBoardTextView(MinesweeperBoard &b) : board(b) {}

char MSBoardTextView::field_char(int row, int col)
{
    if(board.getFieldInfo(row, col)=='_')
    {
        return 219;
    }
        return board.getFieldInfo(row, col);
}

void MSBoardTextView::display()
{
    for(int row=0; row<board.getBoardHeight(); row++)
    {
        for(int col=0; col<board.getBoardWidth(); col++)
        {
            std::cout <<' ' << field_char(row,col);
        }
        std::cout<< std::endl;
    }
}
