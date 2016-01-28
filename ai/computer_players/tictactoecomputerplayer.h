#ifndef TICTACTOECOMPUTERPLAYER_H
#define TICTACTOECOMPUTERPLAYER_H

#include "computerplayer.h"

/**
 * @brief The TicTacToeComputerPlayer class is the ComputerPlayer for TicTacToe
 */
class TicTacToeComputerPlayer : public ComputerPlayer
{
public:
    QString getMoveFromGameState(QString gamestate) const;
};

#endif // TICTACTOECOMPUTERPLAYER_H
