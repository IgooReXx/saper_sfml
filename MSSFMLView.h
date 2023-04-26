//
// Created by IGOR on 04.04.2023.
//

#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H
#include "MinesweeperBoard.h"
#include "SFML/Graphics.hpp"

struct TxSp
{
    sf::Texture tx;
    sf::Sprite sp;
};


class MSSFMLView {
    MinesweeperBoard &board;
    sf::RectangleShape field;
    sf::RectangleShape verticalFieldShade;
    sf::RectangleShape horizontalFieldShade;
    sf::RectangleShape background;

    TxSp empty;
    TxSp flag;
    TxSp mine;
    TxSp numbers[8];
    TxSp end_screen_win;
    TxSp end_screen_loss;
    TxSp* screenObject;

   const int offset =0;
   const int offsetAmout = offset*std::max(board.getBoardHeight(),board.getBoardWidth());
   const int squareSize=std::min(800-offsetAmout,600-offsetAmout)/std::max(board.getBoardWidth(),board.getBoardHeight());
   const int starting_xpos=(800-offsetAmout-board.getBoardWidth()*squareSize)/2;
   const int starting_ypos=(600-offsetAmout-board.getBoardHeight()*squareSize)/2;

   void load_all_txsp();
   void resize_all_txsp();
   TxSp *choose_txsp(int row, int col);
    void display_end_screen(sf::RenderWindow &win);

public:
    MSSFMLView(MinesweeperBoard &b);

    void draw(sf::RenderWindow & win);
   int get_starting_xpos() const;
   int get_starting_ypos() const;
   int get_offset() const;
   int get_squareSize() const;
};


#endif //SAPER_MSSFMLVIEW_H
