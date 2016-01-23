#ifndef TICTACTOEGAMESTATE_H
#define TICTACTOEGAMESTATE_H

#include "../gamestate.h"

/**
 * @brief Represents a TicTacToe game state.
 * Internally the TicTacToe game represents the board as a 2d array of chars, with each square being either an underscore, capital X, or capital O.
 * The first dimension of the array represent the x coordinate on the tic tac toe board, and the second represents the y coordinate with the origin being in the bottom left of the board.
 * The string representation of the board is a 9 character string that goes l-r across the top row, then the second row, then the third row in the X/_/O encoding.
 * The string representation of a move are two numbers with the first being the x coordinate, and the second being the y coordinate
 */
class TicTacToeGameState : public GameState
{
public:
    TicTacToeGameState();
    void initializeGame();
    QString getGameState() const;
    void setGameState(QString gameState);
    void updateGameState(QString move);
    int findWinners() const;
    QList<int> getValidNumberOfPlayers() const;
    int getTurn() const;
    QStringList findValidMoves() const;
    void printGameState() const;

private:
    char board[3][3];
    int playerTurn; //The player whos turn it is
    void incrementTurn();
    void deincrementTurn();
};
#endif // TICTACTOEGAMESTATE_H
