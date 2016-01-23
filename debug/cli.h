#ifndef CLI_H
#define CLI_H

#include "../games/game.h"

class CLI
{
public:
    static void play();

private:
    static void playGame(std::shared_ptr<Game>);
    static void clearScreen();
};

#endif // CLI_H
