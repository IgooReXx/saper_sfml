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
    void board_clear();
    void board_debug_field();
    void board_field_randomize(GameMode mode);
    void board_debug_field2();
public:
    MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode);
    void debug_display() const;
};


#endif //SAPER_MINESWEEPERBOARD_H
