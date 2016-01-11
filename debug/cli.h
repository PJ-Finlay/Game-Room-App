#ifndef CLI_H
#define CLI_H

#include "../games/game.h"

class CLI
{
public:
    static void play();

private:
    static void playGame(Game gameToPlay);
};

#endif // CLI_H
