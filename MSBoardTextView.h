//
// Created by kubab on 25.03.2023.
//

#ifndef SAPER_MSBOARDTEXTVIEW_H
#define SAPER_MSBOARDTEXTVIEW_H
#include "MinesweeperBoard.h"

class MSBoardTextView {
    MinesweeperBoard &board;

    /*
        Returns "█" as a character if field is not revealed.
     */

    char field_char(int row,int col) const;
public:
    /*
        Displays players view of the board.
    */
    void display() const;
    MSBoardTextView(MinesweeperBoard &b);
};


#endif //SAPER_MSBOARDTEXTVIEW_H
