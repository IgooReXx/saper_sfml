//
// Created by kubab on 25.03.2023.
//

#include "MSTextController.h"
#include <string>
#include <iostream>
#include <cctype>

MSTextController::MSTextController(MinesweeperBoard &b, MSBoardTextView &v) : board(b), view(v)
{}
void MSTextController::play()
{
    int input;
    std::string rowstr,colstr;
    int row, col;
    while(board.getGameState()==RUNNING)
    {
        view.display();
        std::cout<<"Choose your action:" << std::endl;
        std::cout<<"1. Reveal field." << std::endl;
        std::cout<<"2. Place/Remove flag." << std::endl;
        std::cin >> input;

        switch(input)
        {
            case 1:
                std::cout << "Input row number:";
                std::cin >> rowstr;
                if(!checkForInteger(rowstr))
                {
                    break;
                }
                row = std::stoi(rowstr);
                std::cout << "Input column number:";

                std::cin >> colstr;
                if(!checkForInteger(colstr))
                {
                    break;
                }
                col = std::stoi(colstr);
                board.revealField(row,col);
                break;
            case 2:
                std::cout << "Input row number:";
                std::cin >> rowstr;
                if(!checkForInteger(rowstr))
                {
                    break;
                }
                row = std::stoi(rowstr);
                std::cout << "Input column number:";
                std::cin >> colstr;
                if(!checkForInteger(colstr))
                {
                    break;
                }
                col = std::stoi(colstr);
                board.toggleFlag(row, col);
                break;
            default:
                break;
        }
        board.checkForWinCondition();
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

bool MSTextController::checkForInteger(std::string str)
{
    for(int indx=0; indx<str.length(); indx++)
    {
        if(!isdigit(str[indx]))
        {
            return false;
        }
    }
    return true;
}