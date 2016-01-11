#include "tictactoecomputerplayer.h"

#include "../../gamestate/individual_game_states/tictactoegamestate.h"
#include "../algorithms/minimax.h"

QString TicTacToeComputerPlayer::getMoveFromGameState(QString gamestate) const
{
    TicTacToeGameState g;
    g.setGameState(gamestate);

    return Minimax::pickMove(&g);

}
