#include "computerplayer.h"

ComputerPlayer::ComputerPlayer(double difficulty)
{
    this->setDifficulty(difficulty);
}

double ComputerPlayer::getDifficulty()
{
    return difficulty;
}

void ComputerPlayer::setDifficulty(double difficulty)
{
    this->difficulty = difficulty;
}




