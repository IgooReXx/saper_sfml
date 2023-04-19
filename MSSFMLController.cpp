//
// Created by c on 4/12/23.
//

#include "MSSFMLController.h"
#include "SFML/Graphics.hpp"


MSSFMLController::MSSFMLController(MinesweeperBoard &b, MSSFMLView &v, sf::RenderWindow &w) : board(b), view(v), window(w)
{}

void MSSFMLController::play(sf::Event &event)
{
    if(!isInsideArea(event))
    {
        return;
    }
   if(!isInsideField(event))
   {
       return;
   }
    int row=(event.mouseButton.y-view.get_starting_ypos())/(view.get_squareSize()+view.get_offset());
    int col=(event.mouseButton.x-view.get_starting_xpos())/(view.get_squareSize()+view.get_offset());
    if (event.mouseButton.button == sf::Mouse::Left)
    {
        board.revealField(row, col);
        board.checkForWinCondition();
    }
    else if (event.mouseButton.button == sf::Mouse::Right)
    {
        board.toggleFlag(row, col);
    }
}


bool MSSFMLController::isInsideArea(sf::Event &event)
{
    int xSize=view.get_squareSize()*board.getBoardWidth()+view.get_offset()*(board.getBoardWidth()-1);
    int ySize=view.get_squareSize()*board.getBoardHeight()+view.get_offset()*(board.getBoardHeight()-1);
    if(event.mouseButton.x<view.get_starting_xpos()) return false;
    if(event.mouseButton.y<view.get_starting_ypos()) return false;
    if(event.mouseButton.x>(view.get_starting_xpos()+xSize)) return false;
    if(event.mouseButton.y>(view.get_starting_ypos()+ySize)) return false;
    return true;
}

bool MSSFMLController::isInsideField(sf::Event &event)
{
    int mousexpos=event.mouseButton.x-view.get_starting_xpos();
    int mouseypos=event.mouseButton.y-view.get_starting_ypos();
    int hitboxSize=view.get_squareSize()+view.get_offset();

    if(mousexpos%hitboxSize>view.get_squareSize()) return false;
    if(mouseypos%hitboxSize>view.get_squareSize()) return false;

    return true;
}