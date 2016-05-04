#ifndef CHECKERS_H
#define CHECKERS_H

#include "../game.h"

#include <memory>

/**
 * @brief Represents a game of Checkers
 */
class Checkers : public Game
{
public:
    Checkers();
    virtual std::shared_ptr<GameState> getGameState() const;
    virtual std::shared_ptr<ComputerPlayer> getComputerPlayer() const;
        GameWidget* getGameWidget() const;
};

#endif // CHECKERS_H
