#include "checkerscomputerplayer.h"

#include "../../gamestate/individual_game_states/checkersgamestate.h"
#include "../algorithms/minimax.h"

QString CheckersComputerPlayer::getMoveFromGameState(QString gamestate) const
{
    CheckersGameState* g = new CheckersGameState;
    g->setGameState(gamestate);

    return Minimax::pickMove(g);

}
