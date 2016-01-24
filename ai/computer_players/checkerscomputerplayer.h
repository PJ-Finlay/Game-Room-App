#ifndef CHECKERSCOMPUTERPLAYER_H
#define CHECKERSCOMPUTERPLAYER_H

#include "computerplayer.h"

class CheckersComputerPlayer : public ComputerPlayer
{
public:
    QString getMoveFromGameState(QString gamestate) const;
};

#endif // CHECKERSCOMPUTERPLAYER_H
