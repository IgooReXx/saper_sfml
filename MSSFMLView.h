//
// Created by IGOR on 04.04.2023.
//

#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H
#include "MinesweeperBoard.h"
#include "SFML/Graphics.hpp"

/*
    Textures made using https://www.pixilart.com/
 */


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

    /*
        Loads textures and sets sprites.
    */
   void load_all_txsp();

    /*
        Resizes sprites to fit the board field.

        Important note:
        Setting board size bigger than 18x18
        causes board fields to be smaller than a singular sprite thus
        all sprites are resized to 0
    */
   void resize_all_txsp();

    /*
        Returns a pointer to TxSp based on field contents.
    */
   TxSp *choose_txsp(int row, int col);

    /*
        Displays end screen based on game state.
    */
    void display_end_screen(sf::RenderWindow &win);

public:
    MSSFMLView(MinesweeperBoard &b);

    /*
        Draws current state of the board.
    */
    void draw(sf::RenderWindow & win);

   int get_starting_xpos() const;
   int get_starting_ypos() const;
   int get_offset() const;
   int get_squareSize() const;
};


#endif //SAPER_MSSFMLVIEW_H
