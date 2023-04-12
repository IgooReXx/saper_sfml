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


    MinesweeperBoard board(8, 7, DEBUG);
    MSSFMLView view (board);

    //board.toggleFlag(0,0);
    //board.revealField(2,3);
    MSSFMLController ctrl(board, view);
    ctrl.play();

    return 0;

}
