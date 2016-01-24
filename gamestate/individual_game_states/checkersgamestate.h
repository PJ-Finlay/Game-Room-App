#ifndef CHECKERSGAMESTATE_H
#define CHECKERSGAMESTATE_H

#include "../gamestate.h"

/**
 * @brief Represents a Checkers game state.
 * Internally the TicTacToe game represents the board as a 2d array of chars, with each square being one of the following characters (_,r,R,b,B)
 * The first dimension of the array represent the x coordinate on the checkers board, and the second represents the y coordinate with the origin being in the bottom left of the board.
 * The string representation of the board is a 64 character string that goes l-r across the top row, then the second row, then the third row in the (_,r,R,b,B) encoding.
 * This is followed by either a 1 or a 2 which indicateds which player's turn it is
 * The string representation of a move are 4 numbers with the first two being the x/y cord. of the piece that is being moved, and the second being the resulting x/y cord.
 * In the case that more than one jump is available that will be a seperate move and after the first move is made playerTurn will not change.
 * Black is always on the bottom of the screen , and starts. This means that black is player 1 and red is player 2
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
    double competitivePosition(int player) const;

private:
    char board[8][8];
    int playerTurn; //The player whos turn it is
    void incrementTurn();
    void deincrementTurn();
    QStringList validMovesForPiece(int x, int y) const;
    QStringList validCaptureMoves(int x, int y) const;
};

#endif // CHECKERSGAMESTATE_H
