#ifndef CHECKERSGAMESTATE_H
#define CHECKERSGAMESTATE_H

#include "../gamestate.h"

/**
 * @brief Represents a Checkers game state.
 * Internally the TicTacToe game represents the board as a 2d array of chars, with each square being one of the following characters (_,r,R,b,B)
 * The first dimension of the array represent the x coordinate on the checkers board, and the second represents the y coordinate with the origin being in the bottom left of the board.
 * The string representation of the board is a 64 character string that goes l-r across the top row, then the second row, then the third row in the (_,r,R,b,B) encoding.
 * The string representation of a move are two numbers with the first being the x coordinate, and the second being the y coordinate
 */
class CheckersGameState : public GameState
{
public:
    CheckersGameState();
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
    char board[8][8];
    int playerTurn; //The player whos turn it is
    void incrementTurn();
    void deincrementTurn();
};

#endif // CHECKERSGAMESTATE_H
