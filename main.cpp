#include "SFML/Graphics.hpp"
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include "MSSFMLController.h"
int main() {
    //MinesweeperBoard plansza(7, 4,DEBUG);
    //plansza.debug_display();
    //MSBoardTextView view(plansza);
    //view.display();
    //MSTextController ctrl(plansza,view);
    //ctrl.play();


    MinesweeperBoard board(8, 7, EASY);
    MSSFMLView view (board);

    //board.toggleFlag(0,0);
    //board.revealField(2,3);

    sf::RenderWindow window(sf::VideoMode(800,600), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    MSSFMLController ctrl(board, view, window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::MouseButtonPressed)
            {
                ctrl.play(event);
            }
        }


        window.clear();
        view.draw(window);
        window.display();
    }

    return 0;

}
