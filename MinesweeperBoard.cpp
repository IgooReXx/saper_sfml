//
// Created by c on 3/8/23.
//

#include "MinesweeperBoard.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>


MinesweeperBoard::MinesweeperBoard()
{
    width=5;
    height=7;
    board_clear();
    board_debug_field();
    board_debug_field2();
}

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{
    this->width=width;
    this->height=height;
    this->mode=mode;
    calculate_mineAmount();
    board_clear();
    if(mode != DEBUG)
    {
        board_field_randomize();
        state=RUNNING;
    }
    else
    {
        //board_debug_field();
        board_debug_field2();
        state=RUNNING;
    }

}

//==============================
//Funkcja wyświetla stan planszy
//==============================
void MinesweeperBoard::debug_display() const
{
    for(int row=0; row<height; row++)
    {
        for (int col=0; col<width; col++)
        {
            std::cout << "[";
            if(board[row][col].hasMine)
            {std::cout << "M";}
            else
            {std::cout << ".";}

            if(board[row][col].isRevealed)
            {std::cout << "o";}
            else
            {std::cout << ".";}

            if(board[row][col].hasFlag)
            {std::cout << "f";}
            else
            {std::cout << ".";}
            std::cout << "]";

        }
        std::cout << std::endl;
    }
}

//====================================
//Funkcja czyści każde pole na planszy
//====================================
void MinesweeperBoard::board_clear()
{
    for(int row=0; row<height; row++)
    {
        for(int col=0; col<width; col++)
        {
            board[row][col].hasFlag=false;
            board[row][col].hasMine=false;
            board[row][col].isRevealed=false;
        }
    }
}

//========================================
//Funkcja ustawia predefiniowany układ min
//========================================
void MinesweeperBoard::board_debug_field()
{
    board[0][0].hasMine=true;
    board[0][0].hasFlag=false;
    board[0][0].isRevealed=false;

    board[1][1].hasMine=false;
    board[1][1].hasFlag=false;
    board[1][1].isRevealed=true;

    board[0][2].hasMine=true;
    board[0][2].hasFlag=true;
    board[0][2].isRevealed=false;
}

//========================================
//Funkcja ustawia predefiniowany układ min
//========================================
void MinesweeperBoard::board_debug_field2()
{
    for(int row=0; row<height; row++)
    {
        for(int col=0; col<width; col++)
        {
            if(row==0)
            {
                board[row][col].hasMine=true;
            }
            else if(row%2==0 and col==0)
            {
                board[row][col].hasMine=true;
            }
            else if(col==row)
            {
                board[row][col].hasMine=true;
            }
        }
    }
}

//==========================================
//Funkcja randomizuje rozkład min na planszy
//==========================================
void MinesweeperBoard::board_field_randomize()
{
    int boardSize=width*height;
    std::vector<int> indxList;
    for(int indx=0; indx<boardSize; indx++)
    {
        indxList.push_back(indx);
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (indxList.begin(), indxList.end(), std::default_random_engine(seed)); // Inicjacja 3. argumentu https://cplusplus.com/reference/algorithm/shuffle/

    for(int i=0; i<boardSize; i++)
    {
        std::cout << indxList[i] << " ";
    }
    std::cout << std::endl;

    int row, col;
    for(int mineNo=0; mineNo<mineAmount; mineNo++)
    {
        row=indxList[mineNo]/width;
        col=indxList[mineNo]%width;
        board[row][col].hasMine=true;
    }
}

void MinesweeperBoard::calculate_mineAmount()
{
    int boardSize=width*height;
    switch(mode)
    {
        case EASY:
            mineAmount = std::ceil(boardSize*0.1);
            break;
        case NORMAL:
            mineAmount = std::ceil(boardSize*0.2);
            break;
        case HARD:
            mineAmount = std::ceil(boardSize*0.3);
            break;
        case DEBUG:
            if(width<height)
            {
                mineAmount=width;
            }
            else
            {
                mineAmount=height;
            }

            mineAmount= mineAmount + width + ((height+1)/2)-2;
            break;

    }
}

// simple getters - return appropriate values (passed to or calculated in constructor)
int MinesweeperBoard::getBoardWidth() const
{
    return width;
}
int MinesweeperBoard::getBoardHeight() const
{
    return height;
}
int MinesweeperBoard::getMineCount() const
{
    return mineAmount;
}

bool MinesweeperBoard::is_inside_board(int row, int col) const
{
    if(row<0 or row>height-1 or col<0 or col>width-1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int MinesweeperBoard::countMines(int row, int col) const
{
    if(!is_inside_board(row, col))
    {
        return -1;
    }
    if(!board[row][col].isRevealed)
    {
        return -1;
    }

    int mineCount=0;
    int rowChk=row-1;
    int colChk;

    for(int rowIndx=0; rowIndx<3; rowIndx++)
    {
        colChk=col-1;
        for(int colIndx=0; colIndx<3; colIndx++)
        {
            if(hasMine(rowChk,colChk))
            {
                mineCount++;
            }
            colChk+=1;
        }
        rowChk+=1;
    }
    if(board[row][col].hasMine)
    {
        mineCount--;
    }
    return mineCount;
}

bool MinesweeperBoard::hasFlag(int row, int col) const
{
    if(is_inside_board(row, col))
    {
        if(board[row][col].hasFlag and !board[row][col].isRevealed)
        {
            return true;
        }
    }
    return false;
}

void MinesweeperBoard::toggleFlag(int row, int col)
{
    if(!is_inside_board(row, col)) return;
    if(board[row][col].isRevealed) return;
    if(state != RUNNING) return;

    if(!board[row][col].hasFlag)
    {
        board[row][col].hasFlag=true;
    }
    else
    {
        board[row][col].hasFlag=false;
    }
}

void MinesweeperBoard::revealField(int row, int col)
{
    if(!is_inside_board(row, col)) return;
    if(board[row][col].isRevealed) return;
    if(state != RUNNING) return;
    if(board[row][col].hasFlag) return;

    if(!board[row][col].hasMine)
    {
        moveNo++;
        board[row][col].isRevealed=true;
        if(getFieldInfo(row, col)==' ')
        {
            reveal_all_empty_fields(row, col);
        }
        isFirstMove=false;
        checkForWinCondition();
        return;
    }

        bool mineMoved=false;
        if(isFirstMove and mode!=DEBUG)
        {
            for(int rowindx=0; rowindx<width; rowindx++)
            {
                for(int colindx=0; colindx<height; colindx++)
                {
                    if(!board[rowindx][colindx].hasMine)
                    {
                        board[row][col].hasMine=false;
                        board[row][col].isRevealed=true;
                        board[rowindx][colindx].hasMine=true;
                        mineMoved=true;
                        if(getFieldInfo(row, col)==' ')
                        {
                            reveal_all_empty_fields(row, col);
                        }
                        break;
                    }
                }
                if(mineMoved)
                {
                    break;
                }
            }
            isFirstMove=false;
            return;
        }
        board[row][col].isRevealed=true;
        state=FINISHED_LOSS;

}

bool MinesweeperBoard::isRevealed(int row, int col) const
{
    if(is_inside_board(row,col))
    {
        if(board[row][col].isRevealed)
        {
            return true;
        }
    }
    return false;
}

GameState MinesweeperBoard::getGameState() const
{
    return state;
}

bool MinesweeperBoard::hasMine(int row, int col) const
{
    if(!is_inside_board(row,col)) return false;
    if(board[row][col].hasMine)
    {
        return true;
    }
    return false;
}

char MinesweeperBoard::getFieldInfo(int row, int col) const
{
    if(!is_inside_board(row,col)) return '#';
    if(!isRevealed(row, col) and hasFlag(row, col)) return 'F';
    if(!isRevealed(row, col) and !hasFlag(row,col)) return '_';
    if(isRevealed(row, col) and hasMine(row, col)) return 'x';
    if(isRevealed(row, col) and countMines(row, col)==0) return ' ';
    if(isRevealed(row, col) and countMines(row, col)>0) return countMines(row, col)+'0';
    return '0';
}

void MinesweeperBoard::checkForWinCondition()
{
    if((moveNo)==((width*height)-mineAmount))
    {
        state=FINISHED_WIN;
    }
}

void MinesweeperBoard::reveal_all_empty_fields(int row, int col)
{
    int rowChk=row-1;
    int colChk;

    for(int rowIndx=0; rowIndx<3; rowIndx++)
    {
        colChk=col-1;
        for(int colIndx=0; colIndx<3; colIndx++)
        {
            if(!isRevealed(rowChk, colChk))
            {
                revealField(rowChk,colChk);
            }
            colChk+=1;
        }
        rowChk+=1;
    }
}

void MinesweeperBoard::init()
{
    if(mode != DEBUG)
    {
        board_field_randomize();
        state=RUNNING;
    }
    else
    {
        board_debug_field2();
        state=RUNNING;
    }
}

void MinesweeperBoard::restart()
{
    moveNo=0;
    isFirstMove=true;
    board_clear();
    init();
}

void MinesweeperBoard::reveal_adjacent(int row, int col)
{
    if(!is_inside_board(row, col)) return;
    if(getFieldInfo(row, col) == (countFlags(row, col))+'0' )
    {
        int rowChk=row-1;
        int colChk;

        for(int rowIndx=0; rowIndx<3; rowIndx++)
        {
            colChk=col-1;
            for(int colIndx=0; colIndx<3; colIndx++)
            {
                revealField(rowChk,colChk);
                colChk+=1;
            }
            rowChk+=1;
        }
    }
}

int MinesweeperBoard::countFlags(int row, int col) const
{
    if(!is_inside_board(row, col))
    {
        return -1;
    }
    if(!board[row][col].isRevealed)
    {
        return -1;
    }

    int flagCount=0;
    int rowChk=row-1;
    int colChk;

    for(int rowIndx=0; rowIndx<3; rowIndx++)
    {
        colChk=col-1;
        for(int colIndx=0; colIndx<3; colIndx++)
        {
            if(hasFlag(rowChk,colChk))
            {
                flagCount++;
            }
            colChk+=1;
        }
        rowChk+=1;
    }

    return flagCount;
}