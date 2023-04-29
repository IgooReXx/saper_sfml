//
// Created by kubab on 25.03.2023.
//

#ifndef SAPER_MSTEXTCONTROLLER_H
#define SAPER_MSTEXTCONTROLLER_H
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include <string>

class MSTextController {
    MinesweeperBoard &board;
    MSBoardTextView &view;
    /*
        Checks whether user input is an integer.
     */
    bool checkForInteger(std::string str) const;
public:
    MSTextController(MinesweeperBoard &b, MSBoardTextView &v);
    /*
        Allows for interaction with board through text input.
    */
    void play();
};


#endif //SAPER_MSTEXTCONTROLLER_H
