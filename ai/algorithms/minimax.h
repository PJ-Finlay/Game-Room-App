#ifndef MINIMAX_H
#define MINIMAX_H

#include "../../gamestate/gamestate.h"

/**
 * @brief The Minimax class implements the Minimax algorithm for playing GameState's
 */
class Minimax
{
public:
    /**
     * @brief Picks a move based on a pointer to a GameState
     * @param gamestate A pointer to the GameState that is being evaluated
     * @return The chosen move
     */
    static QString pickMove(GameState* gamestate);

private:
<<<<<<< HEAD
    static double getValueOfMove(GameState* gamestate, QString move, int maxDepth = 5, int currentDepth = 0);
=======
    /**
     * @brief Finds the value of a move between -1 and 1 of a  move that can be made on a GameState
     * @param gamestate The gamestate to be evaluated
     * @param move The move that is being evaluated
     * @param maxDepth The max move depth that should be evaluated
     * @param currentDepth The current depth
     * @return
     */
    static double getValueOfMove(GameState* gamestate, QString move, int maxDepth = 4, int currentDepth = 0);
>>>>>>> 28647dabb045b6dba3d00317afd182e45ad49d22
};

#endif // MINIMAX_H
