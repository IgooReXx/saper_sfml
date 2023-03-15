//
// Created by c on 3/8/23.
//

#ifndef SAPER_MINESWEEPERBOARD_H
#define SAPER_MINESWEEPERBOARD_H
enum GameMode{ DEBUG, EASY, NORMAL, HARD };

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

class MinesweeperBoard
{
    // wybierz jedno z poniższych

    // sugerowane:
    // Array2D<Field> board;

    // tablica 2D
    Field board[100][100];

    // wektor wektorów
    // std::vector<std::vector<Field>> board;

    // niezbędne jeśli użyjecie tablicy 2D, ale w każdym
    // przypadku wygodne
    int width;                // rzeczywista szerokość planszy
    int height;               // rzeczywista wysokość planszy
    int mineAmount;
    void calculate_mineAmount(GameMode mode);
    void board_clear();
    void board_debug_field();
    void board_field_randomize();
    void board_debug_field2();
    bool is_inside_board(int row, int col) const;
    bool check_for_mine(int row, int col) const;
public:
    MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode);
    void debug_display() const;

    // simple getters - return appropriate values (passed to or calculated in constructor)
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;

    // count mines around (row,col) position
    // if the field at (row,col) was not revealed - return -1
    // if either row or col is outside board      - return -1
    // otherwise - return mine count around this field
    // Examples for DEBUG layout on 10x10 board (assuming the field is already revealed)
    // - countMines(1,0) should return 4
    // - countMines(2,9) should return 0
    // - countMines(2,1) should return 3
    // - countMines(6,7) should return 2
    int countMines(int row, int col) const;

};


#endif //SAPER_MINESWEEPERBOARD_H
