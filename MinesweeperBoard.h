//
// Created by c on 3/8/23.
//

#ifndef SAPER_MINESWEEPERBOARD_H
#define SAPER_MINESWEEPERBOARD_H
enum GameMode { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

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
    int mineAmount;           // ilość min na planszy
    int moveNo=0;
    GameMode mode;            // aktualny tryb gry
    GameState state;          // aktualny stan gry
    bool isFirstMove=true;
    /*
        Calculates number of mines based on set difficulty.
        0.1 * board size for EASY
        0.2 * board size for NORMAL
        0.3 * board size for HARD
        And assigns value calculated to mineAmount.
    */

    void calculate_mineAmount();

    /*
        Clears all board fields, by setting all of field contents to false.
    */

    void board_clear();

    /*
        Sets up a predefined mine placement for a board.
    */

    void board_debug_field();
    void board_debug_field2();

    /*
        Randomizes placement of mines on the board.
    */

    void board_field_randomize();

    /*
        Checks whether a field is inside of the board.
     */

    bool is_inside_board(int row, int col) const;

    /*
        Checks for mine inside a field.
     */

    bool hasMine(int row, int col) const;
public:
    MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode);
    void debug_display() const;

    // simple getters - return appropriate values (passed to or calculated in constructor)
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;

    /*
     count mines around (row,col) position
     if the field at (row,col) was not revealed - return -1
     if either row or col is outside board      - return -1
     otherwise - return mine count around this field
     Examples for DEBUG layout on 10x10 board (assuming the field is already revealed)
     - countMines(1,0) should return 4
     - countMines(2,9) should return 0
     - countMines(2,1) should return 3
     - countMines(6,7) should return 2
     */
    int countMines(int row, int col) const;

    /*
     return true if the field at (row,col) position was marked with flag
     return false if any of the following is true:
     - row or col is outside board
     - there is no flag on the field
     - field was already revealed
     */
    bool hasFlag(int row, int col) const;

    /*
     if the field at (row,col) was not revealed - change flag status for this field
     Do nothing if any of the following is true
     - field was already revealed
     - either row or col is outside board
     - game is already finished
     */
    void toggleFlag(int row, int col);

    /*
     try to reveal the field at (row,col)
     Do nothing if any of the following is true
     - field was already revealed
     - either row or col is outside board
     - game is already finished
     - there is a flag on the field

     If the field was not revealed and there is no mine on it - reveal it
     If the field was not revealed and there is a mine on it:
     - if its the first player action - move mine to another location, reveal field (not in DEBUG mode!)
     - reveal it and finish game
     */
    void revealField(int row, int col);

    // return true if the field was revealed
    bool isRevealed(int row, int col) const;

    /*
    return current game state:
    - FINISHED_LOSS - if the player revealed field with mine
    - FINISHED_WIN  - if the player won the game (all unrevealed fields have mines)
    - RUNNING       - if the game is not yet finished
     */
    GameState getGameState() const;

    /*
     convenience function - returns useful information about field in one function call
     if row or col is outside board                         - return '#' character
     if the field is not revealed and has a flag            - return 'F' character
     if the field is not revealed and does not have a flag  - return '_' (underscore) character
     if the field is revealed and has mine                  - return 'x' character
     if the field is revealed and has 0 mines around        - return ' ' (space) character
     if the field is revealed and has some mines around     - return '1' ... '8' (number of mines as a digit)
     */
    char getFieldInfo(int row, int col) const;


    void checkForWinCondition();

};


#endif //SAPER_MINESWEEPERBOARD_H
