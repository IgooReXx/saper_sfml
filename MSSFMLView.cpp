//
// Created by IGOR on 04.04.2023.
//

#include "MSSFMLView.h"
#include "MinesweeperBoard.h"
#include "SFML/Graphics.hpp"
#include <iostream>

MSSFMLView::MSSFMLView(MinesweeperBoard &b) : board(b)
{
    field = sf::RectangleShape(sf::Vector2f(squareSize, squareSize));
    background = sf::RectangleShape(sf::Vector2f(800, 600));
    verticalFieldShade = sf::RectangleShape(sf::Vector2f(squareSize/10, squareSize));
    horizontalFieldShade = sf::RectangleShape(sf::Vector2f(squareSize, squareSize/10));
    field.setFillColor(sf::Color(180,180,180));
    background.setFillColor(sf::Color(100,100,100));
    load_all_txsp();
    resize_all_txsp();
}

void MSSFMLView::draw(sf::RenderWindow &win)
{
    win.draw(background);
    int xpos=starting_xpos;
    int ypos=starting_ypos;
    field.setPosition(xpos,ypos);
    horizontalFieldShade.setPosition(xpos, ypos);
    verticalFieldShade.setPosition(xpos,ypos);
    horizontalFieldShade.setFillColor(sf::Color(201, 201, 201));
    verticalFieldShade.setFillColor(sf::Color(201, 201, 201));


    for(int row=0; row<board.getBoardHeight(); row++)
    {
        for(int col=0; col<board.getBoardWidth(); col++)
        {
            if(board.isRevealed(row, col))
            {
                field.setFillColor(sf::Color(107,107,107));
                horizontalFieldShade.setFillColor(sf::Color(70, 70, 70));
                verticalFieldShade.setFillColor(sf::Color(70, 70, 70));
            }
            else
            {
                field.setFillColor(sf::Color(180,180,180));
                horizontalFieldShade.setFillColor(sf::Color(201, 201, 201));
                verticalFieldShade.setFillColor(sf::Color(201, 201, 201));
            }
            win.draw(field);

            win.draw(horizontalFieldShade);
            win.draw(verticalFieldShade);

            horizontalFieldShade.setPosition(xpos, ypos+squareSize-squareSize/10);
            verticalFieldShade.setPosition(xpos+squareSize-squareSize/10, ypos);
            horizontalFieldShade.setFillColor(sf::Color(70, 70, 70));
            verticalFieldShade.setFillColor(sf::Color(70, 70, 70));

            win.draw(horizontalFieldShade);
            win.draw(verticalFieldShade);



            screenObject=choose_txsp(row,col);
            int spriteSize = empty.sp.getGlobalBounds().width; // assumes all sprites are the same size
            int Offset = (squareSize - spriteSize)/2;
            screenObject->sp.setPosition(xpos+Offset, ypos+Offset);
            win.draw(screenObject->sp);
            field.setPosition(xpos+=(squareSize+offset),ypos);
            horizontalFieldShade.setPosition(xpos, ypos);
            verticalFieldShade.setPosition(xpos,ypos);

        }
        xpos=(800-offsetAmout-(board.getBoardWidth()*squareSize))/2;
        ypos+=(squareSize+offset);
        field.setPosition(xpos,ypos);
        horizontalFieldShade.setPosition(xpos, ypos);
        verticalFieldShade.setPosition(xpos,ypos);
        screenObject->sp.setPosition(xpos,ypos);
    }

    if(board.getGameState()!=RUNNING)
    {
        display_end_screen(win);
    }

}

int MSSFMLView::get_starting_xpos() const
{
    return starting_xpos;
}
int MSSFMLView::get_starting_ypos() const
{
    return starting_ypos;
}
int MSSFMLView::get_offset() const
{
    return offset;
}
int MSSFMLView::get_squareSize() const
{
    return squareSize;
}

void MSSFMLView::load_all_txsp()
{
    if(!empty.tx.loadFromFile("../textury/empty.png", sf::IntRect(0, 0, 32, 32)))
    {
        exit(1);
    }
    empty.sp.setTexture(empty.tx);
    
    if(!flag.tx.loadFromFile("../textury/flag.png", sf::IntRect(0, 0, 32, 32)))
    {
        exit(1);
    }
    flag.sp.setTexture(flag.tx);

    if(!mine.tx.loadFromFile("../textury/mine.png", sf::IntRect(0, 0, 32, 32)))
    {
        exit(1);
    }
    mine.sp.setTexture(mine.tx);

    if(!numbers[0].tx.loadFromFile("../textury/one.png", sf::IntRect(0, 0, 32, 32)))
    {
        exit(1);
    }
    numbers[0].sp.setTexture(numbers[0].tx);

    if(!numbers[1].tx.loadFromFile("../textury/two.png", sf::IntRect(0, 0, 32, 32)))
    {
        exit(1);
    }
    numbers[1].sp.setTexture(numbers[1].tx);
    
    if(!numbers[2].tx.loadFromFile("../textury/three.png", sf::IntRect(0, 0, 32, 32)))
    {
        exit(1);
    }
    numbers[2].sp.setTexture(numbers[2].tx);

    if(!numbers[3].tx.loadFromFile("../textury/four.png", sf::IntRect(0, 0, 32, 32)))
    {
        exit(1);
    }
    numbers[3].sp.setTexture(numbers[3].tx);
    
    if(!numbers[4].tx.loadFromFile("../textury/five.png", sf::IntRect(0, 0, 32, 32)))
    {
        exit(1);
    }
    numbers[4].sp.setTexture(numbers[4].tx);

    if(!numbers[5].tx.loadFromFile("../textury/six.png", sf::IntRect(0, 0, 32, 32)))
    {
        exit(1);
    }
    numbers[5].sp.setTexture(numbers[5].tx);

    if(!numbers[6].tx.loadFromFile("../textury/seven.png", sf::IntRect(0, 0, 32, 32)))
    {
        exit(1);
    }
    numbers[6].sp.setTexture(numbers[6].tx);
    
    if(!numbers[7].tx.loadFromFile("../textury/eight.png", sf::IntRect(0, 0, 32, 32)))
    {
        exit(1);
    }
    numbers[7].sp.setTexture(numbers[7].tx);

    if(!end_screen_loss.tx.loadFromFile("../textury/lost.png", sf::IntRect(0, 0, 100, 100)))
    {
        exit(1);
    }
    end_screen_loss.sp.setTexture(end_screen_loss.tx);

    if(!end_screen_win.tx.loadFromFile("../textury/won.png", sf::IntRect(0, 0, 100, 100)))
    {
        exit(1);
    }
    end_screen_win.sp.setTexture(end_screen_win.tx);


}

void MSSFMLView::resize_all_txsp() 
{
    empty.sp.setScale(squareSize/empty.sp.getTexture()->getSize().x,squareSize/empty.sp.getTexture()->getSize().y);
    flag.sp.setScale(squareSize/flag.sp.getTexture()->getSize().x,squareSize/flag.sp.getTexture()->getSize().y);
    mine.sp.setScale(squareSize/mine.sp.getTexture()->getSize().x,squareSize/mine.sp.getTexture()->getSize().y);
    for(int idx=0; idx<8; ++idx)
    {
        numbers[idx].sp.setScale(squareSize / numbers[idx].sp.getTexture()->getSize().x, squareSize / numbers[idx].sp.getTexture()->getSize().y);
    }

}

TxSp *MSSFMLView::choose_txsp(int row, int col)
{
        switch(board.getFieldInfo(row,col))
        {
            case 'F':
                return &flag;
            case 'x':
                return &mine;
            case '1':
                return &numbers[0];
            case '2':
                return &numbers[1];
            case '3':
                return &numbers[2];
            case '4':
                return &numbers[3];
            case '5':
                return &numbers[4];
            case '6':
                return &numbers[5];
            case '7':
                return &numbers[6];
            case '8':
                return &numbers[7];
            default:
                return &empty;
        }
}

void MSSFMLView::display_end_screen(sf::RenderWindow &win)
{
    TxSp* displayed_end_screen;
    if(board.getGameState()==FINISHED_LOSS)
    {
        displayed_end_screen=&end_screen_loss;
    }
    else
    {
        displayed_end_screen = &end_screen_win;
    }
    displayed_end_screen->sp.setPosition(800/2-50, 600/2-50);
    win.draw(displayed_end_screen->sp);
}