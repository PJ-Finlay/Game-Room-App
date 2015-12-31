#include "debugsandbox.h"

#include "gamestate/individual_game_states/tictactoegamestate.h"

void DebugSandbox::test()
{
    TicTacToeGameState g;
    g.initializeGame();
    g.printGameState();
}
