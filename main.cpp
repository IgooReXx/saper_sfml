#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
int main() {
    MinesweeperBoard plansza(2, 2,EASY);
    plansza.debug_display();
    MSBoardTextView view(plansza);
    //view.display();
    MSTextController ctrl(plansza,view);
    ctrl.play();
}
