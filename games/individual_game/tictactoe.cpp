#include "tictactoe.h"

TicTacToe::TicTacToe() : Game()
{
    this->setName("Tic Tac Toe");
}

std::shared_ptr<GameState> TicTacToe::getGameState() const
{
    std::shared_ptr<TicTacToeGameState> toReturn(new TicTacToeGameState());
    return toReturn;
}

