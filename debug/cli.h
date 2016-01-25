#ifndef CLI_H
#define CLI_H

#include "../games/game.h"

/**
 * @brief A command line interface that uses GameList to get all of the Games, and then play them with both human and computer players
 */
class CLI
{
public:
    /**
     * @brief Launches the CLI
     */
    static void play();

private:
    /**
     * @brief Plays the game described by a shared_ptr to a game
     */
    static void playGame(std::shared_ptr<Game>);

    /**
     * @brief Clears the screen, since there is no direct way to do this that I am aware of this needs to be changed by commenting/uncommenting a line
     * based on platform to execute the shell command for clearing the screen
     */
    static void clearScreen();
};

#endif // CLI_H
