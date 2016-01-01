#ifndef TICTACTOECOMPUTERPLAYER_H
#define TICTACTOECOMPUTERPLAYER_H

#include "computerplayer.h"

#include <QString>

class TicTacToeComputerPlayer : public ComputerPlayer
{
public:
    QString getMoveFromGameState(QString gamestate);
};

#endif // TICTACTOECOMPUTERPLAYER_H
