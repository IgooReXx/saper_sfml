//
// Created by c on 4/12/23.
//

#ifndef SAPER_MSSFMLCONTROLLER_H
#define SAPER_MSSFMLCONTROLLER_H


#include "MinesweeperBoard.h"
#include "MSSFMLView.h"

class MSSFMLController {
    MinesweeperBoard &board;
    MSSFMLView &view;
    bool isInsideArea(int xpos, int ypos);
    bool isInsideField(int xpos, int ypos);
public:
    MSSFMLController(MinesweeperBoard &b, MSSFMLView &v);
    void play();

};


#endif //SAPER_MSSFMLCONTROLLER_H
