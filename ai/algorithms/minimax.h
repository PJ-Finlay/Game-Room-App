#ifndef MINIMAX_H
#define MINIMAX_H

#include "../../gamestate/gamestate.h"

class Minimax
{
public:
    static QString pickMove(GameState* gamestate);

private:
    static double getValueOfMove(GameState* gamestate, QString move);
};

#endif // MINIMAX_H
