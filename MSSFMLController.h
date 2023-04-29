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
    /*
        Both functions check wether event happened inside of playable area
    */
    bool isInsideArea(sf::Event &event) const;
    bool isInsideField(sf::Event &event) const;
public:
    MSSFMLController(MinesweeperBoard &b, MSSFMLView &v, sf::RenderWindow &w);
    /*
        Allows for interaction with board through mouse input.
    */
    void play(sf::Event &event);
};


#endif //SAPER_MSSFMLCONTROLLER_H
