#ifndef CHECKERSCOMPUTERPLAYER_H
#define CHECKERSCOMPUTERPLAYER_H

#include "computerplayer.h"

/**
 * @brief The CheckersComputerPlayer class is the ComputerPlayer for Checkers.
 * It uses the Minimax algorithm
 */
class CheckersComputerPlayer : public ComputerPlayer
{
public:
    QString getMoveFromGameState(QString gamestate) const;
};

#endif // CHECKERSCOMPUTERPLAYER_H
