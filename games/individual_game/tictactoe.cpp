#include "tictactoe.h"

#include "../../ai/computer_players/tictactoecomputerplayer.h"
#include "../../gamestate/individual_game_states/tictactoegamestate.h"

TicTacToe::TicTacToe() : Game()
{
    this->setName("Tic Tac Toe");
}

std::shared_ptr<GameState> TicTacToe::getGameState() const
{
    qDebug() << "TicTacToe.h - getGameState";
    std::shared_ptr<TicTacToeGameState> toReturn(new TicTacToeGameState());
    return toReturn;
}

std::shared_ptr<ComputerPlayer> TicTacToe::getComputerPlayer() const
{
    qDebug() << "TicTacToe.h - getComputerPlayer";
    std::shared_ptr<TicTacToeComputerPlayer> toReturn(new TicTacToeComputerPlayer());
    return toReturn;
}
