#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "../game.h"

#include <memory>

/**
 * @brief Represents a Game of TicTacToe
 */
class TicTacToe : public Game
{
public:
    TicTacToe();
    virtual std::shared_ptr<GameState> getGameState() const;
    virtual std::shared_ptr<ComputerPlayer> getComputerPlayer() const;

};

#endif // TICTACTOE_H
