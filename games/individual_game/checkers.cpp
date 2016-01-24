#include "checkers.h"

#include "../../ai/computer_players/tictactoecomputerplayer.h"
#include "../../gamestate/individual_game_states/checkersgamestate.h"

Checkers::Checkers() : Game()
{
    this->setName("Checkers");
}

std::shared_ptr<GameState> Checkers::getGameState() const
{
    std::shared_ptr<CheckersGameState> toReturn(new CheckersGameState());
    return toReturn;
}

std::shared_ptr<ComputerPlayer> Checkers::getComputerPlayer() const
{
    std::shared_ptr<TicTacToeComputerPlayer> toReturn(new TicTacToeComputerPlayer());
    return toReturn;
}
