//
// Created by IGOR on 04.04.2023.
//

#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H
#include "MinesweeperBoard.h"
#include "SFML/Graphics.hpp"
#include <algorithm>
#include <iostream>

class MSSFMLView {
    MinesweeperBoard &board;
    sf::RectangleShape field;
    sf::Font font;
   const int offset = 3;
   const int offsetAmout = offset*std::max(board.getBoardHeight(),board.getBoardWidth());
   const int squareSize=std::min(800-offsetAmout,600-offsetAmout)/std::max(board.getBoardWidth(),board.getBoardHeight());
   const int starting_xpos=(800-offsetAmout-board.getBoardWidth()*squareSize)/2;
   const int starting_ypos=(600-offsetAmout-board.getBoardHeight()*squareSize)/2;
    char field_char(int row, int col);
public:
    MSSFMLView(MinesweeperBoard &b);

    void draw(sf::RenderWindow & win);
   int get_starting_xpos() const;
   int get_starting_ypos() const;
   int get_offset() const;
   int get_squareSize() const;
};


#endif //SAPER_MSSFMLVIEW_H
