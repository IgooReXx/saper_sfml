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
    sf::RenderWindow &window;
    bool isInsideArea(int xpos, int ypos);
    bool isInsideField(sf::Event &event);
public:
    MSSFMLController(MinesweeperBoard &b, MSSFMLView &v, sf::RenderWindow &w);
    void play(sf::Event &event);
};


#endif //SAPER_MSSFMLCONTROLLER_H
