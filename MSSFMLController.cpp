//
// Created by c on 4/12/23.
//

#include "MSSFMLController.h"


MSSFMLController::MSSFMLController(MinesweeperBoard &b, MSSFMLView &v) : board(b), view(v)
{}

void MSSFMLController::play()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::MouseButtonPressed)
            {
                if(!isInsideArea(event.mouseButton.x, event.mouseButton.y))
                {
                    break;
                }
                if(!isInsideField(event.mouseButton.x, event.mouseButton.y))
                {
                    break;
                }
                int row=(event.mouseButton.y-view.get_starting_ypos())/view.get_squareSize();
                std::cout << row  << " ";
                int col=(event.mouseButton.x-view.get_startig_xpos())/view.get_squareSize();
                std::cout << col << std::endl;
                //if()
            }
        }


        window.clear();
        view.draw(window);
        window.display();
    }
}

bool MSSFMLController::isInsideArea(int xpos, int ypos)
{
    int xsize=view.get_squareSize()*board.getBoardWidth()+view.get_offset()*(board.getBoardWidth()-1);
    int ysize=view.get_squareSize()*board.getBoardHeight()+view.get_offset()*(board.getBoardHeight()-1);
    if(xpos<view.get_startig_xpos()) return false;
    if(ypos<view.get_starting_ypos()) return false;
    if(xpos>(view.get_startig_xpos()+xsize)) return false;
    if(ypos>(view.get_starting_ypos()+ysize)) return false;
    return true;
}

bool MSSFMLController::isInsideField(int xpos, int ypos)
{
    if((xpos-view.get_startig_xpos())%view.get_squareSize()!=0) return false;
    if((ypos-view.get_starting_ypos())%view.get_squareSize()!=0) return false;
    return true;
}