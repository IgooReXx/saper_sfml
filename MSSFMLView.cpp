//
// Created by IGOR on 04.04.2023.
//

#include "MSSFMLView.h"

MSSFMLView::MSSFMLView(MinesweeperBoard &b) : board(b)
{
    field = sf::RectangleShape(sf::Vector2f(squareSize, squareSize));
    field.setFillColor(sf::Color(223,223,223));
    if(!font.loadFromFile("../fonts/Ubuntu-B.ttf"))
    {
        exit(1);
    }
    if(!txFlag.loadFromFile("../flag.png", sf::IntRect(0, 0, 32, 32)))
    {
        exit(1);
    }
    spFlag.setTexture(txFlag);
    spFlag.setScale(squareSize/spFlag.getTexture()->getSize().x,squareSize/spFlag.getTexture()->getSize().y);
}

void MSSFMLView::draw(sf::RenderWindow &win)
{
    sf::Text text;
    text.setFont(font);
    int xpos=starting_xpos;
    int ypos=starting_ypos;
    field.setPosition(xpos,ypos);
    spFlag.setPosition(xpos, ypos);


    for(int row=0; row<board.getBoardHeight(); row++)
    {
        for(int col=0; col<board.getBoardWidth(); col++)
        {
            if(board.isRevealed(row, col))
            {
                field.setFillColor(sf::Color(107,107,107));
            }
            else
            {
                field.setFillColor(sf::Color(223,223,223));
            }
            win.draw(field);
            if(board.hasFlag(row,col))
            {
                win.draw(spFlag);
            }
            //text.setPosition(xpos+25, ypos-5);
            field.setPosition(xpos+=(squareSize+offset),ypos);
            spFlag.setPosition(xpos,ypos);
            //text.setString(field_char(row, col));
            //text.setCharacterSize(squareSize-20);
            //text.setFillColor(sf::Color::Red);
            //win.draw(text);

        }
        xpos=(800-offsetAmout-(board.getBoardWidth()*squareSize))/2;
        ypos+=(squareSize+offset);
        field.setPosition(xpos,ypos);
        spFlag.setPosition(xpos,ypos);
    }

}

char MSSFMLView::field_char(int row, int col)
{
    if(board.getFieldInfo(row, col)=='_')
    {
        return ' ';
    }
    return board.getFieldInfo(row, col);
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