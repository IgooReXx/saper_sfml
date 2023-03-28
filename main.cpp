#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
int main() {
    MinesweeperBoard plansza(10, 10,HARD);
    //plansza.debug_display();
    MSBoardTextView view(plansza);
    //view.display();
    MSTextController ctrl(plansza,view);
    ctrl.play();
}
