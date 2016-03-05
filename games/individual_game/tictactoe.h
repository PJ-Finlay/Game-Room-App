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
    std::shared_ptr<GameState> getGameState() const;
    std::shared_ptr<ComputerPlayer> getComputerPlayer() const;
    GameWidget* getGameWidget() const;

};

#endif // TICTACTOE_H
