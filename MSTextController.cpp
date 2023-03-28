//
// Created by kubab on 25.03.2023.
//

#include "MSTextController.h"
#include <iostream>

MSTextController::MSTextController(MinesweeperBoard &b, MSBoardTextView &v) : board(b), view(v)
{}
void MSTextController::play()
{
    int input=' ';
    int row=0,col=0;
    while(board.getGameState()==RUNNING)
    {
        board.checkForWinCondition();
        view.display();
        std::cout<<"Choose your action:" << std::endl;
        std::cout<<"1. Reveal field." << std::endl;
        std::cout<<"2. Place/Remove flag." << std::endl;
        std::cin >> input;

        switch(input)
        {
            case 1:
                std::cout << "Input row number:";
                std::cin >> row;
                std::cout << "Input column number:";
                std::cin >> col;
                board.revealField(row,col);
                break;
            case 2:
                std::cout << "Input row number:";
                std::cin >> row;
                std::cout << "Input column number:";
                std::cin >> col;
                board.toggleFlag(row, col);
                break;
            default:
                break;
        }

    }
    if(board.getGameState()==FINISHED_LOSS)
    {
        std::cout << "Game over." << std::endl;
    }
    if(board.getGameState()==FINISHED_WIN)
    {
        std::cout << "Game won." << std::endl;
    }
}