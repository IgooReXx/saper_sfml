//
// Created by kubab on 25.03.2023.
//

#ifndef SAPER_MSTEXTCONTROLLER_H
#define SAPER_MSTEXTCONTROLLER_H
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
class MSTextController {
    MinesweeperBoard &board;
    MSBoardTextView &view;
public:
    MSTextController(MinesweeperBoard &b, MSBoardTextView &v);
    void play();
};


#endif //SAPER_MSTEXTCONTROLLER_H
