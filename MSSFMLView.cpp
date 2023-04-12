//
// Created by IGOR on 04.04.2023.
//

#include "MSSFMLView.h"

MSSFMLView::MSSFMLView(MinesweeperBoard &b) : board(b)
{
    field = sf::RectangleShape(sf::Vector2f(squareSize, squareSize));
    field.setFillColor(sf::Color(223,223,223));
    if(!font.loadFromFile("/home/c/275435/git/sfml_saper_igor_bujak/fonts/Ubuntu-B.ttf"))
    {
        exit(1);
    }
}

void MSSFMLView::draw(sf::RenderWindow &win)
{
    sf::Text text;
    text.setFont(font);
    int xpos=starting_xpos;
    int ypos=starting_ypos;
    field.setPosition(xpos,ypos);

    for(int row=0; row<board.getBoardHeight(); row++)
    {
        for(int col=0; col<board.getBoardWidth(); col++)
        {
            win.draw(field);
            text.setPosition(xpos+25, ypos-5);
            field.setPosition(xpos+=(squareSize+offset),ypos);
            text.setString(field_char(row, col));
            text.setCharacterSize(squareSize-20);
            text.setFillColor(sf::Color::Red);
            win.draw(text);

        }
        xpos=(800-offsetAmout-(board.getBoardWidth()*squareSize))/2;
        ypos+=(squareSize+offset);
        field.setPosition(xpos,ypos);
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

int MSSFMLView::get_startig_xpos() const
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