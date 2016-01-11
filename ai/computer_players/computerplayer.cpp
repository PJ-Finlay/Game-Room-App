#include "computerplayer.h"

ComputerPlayer::ComputerPlayer(double difficulty)
{
    this->setDifficulty(difficulty);
}

double ComputerPlayer::getDifficulty() const
{
    return difficulty;
}

void ComputerPlayer::setDifficulty(double difficulty)
{
    this->difficulty = difficulty;
}




