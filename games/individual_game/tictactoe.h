#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <memory>

#include "../game.h"
#include "../../gamestate/individual_game_states/tictactoegamestate.h"

/**
 * @brief Represents a Game of TicTacToe
 */
class TicTacToe : public Game
{
public:
    /**
     * @brief Creates a TicTacToe object
     */
    TicTacToe();

    /**
     * @brief Gets the a shared_ptr TicTacToeGameState
     * @return The TicTacToeGameState
     */
    virtual std::shared_ptr<GameState> getGameState() const;
};

#endif // TICTACTOE_H
