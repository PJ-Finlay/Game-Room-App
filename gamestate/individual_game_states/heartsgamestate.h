#ifndef HEARTS_H
#define HEARTS_H

#include "../game_state_types/trickbasedgamestate.h"

/**
 * @brief Represents a game of Hearts game state
 * Move notation:
 *  Playing Card - CardID
 *  Passing Cards - CardIDs (| seperated)
 * Modes:
 *  0 - Passing mode
 *  1 - Trick Taking Mode
 *  3 - Choosing how to allocate points after shooting the moon
 * OtherInfo:
 *  The Type of passing done this hand (R/L/A/N)
 * Example (With reduced cards for simplicity):
 * 0-R-|13|0|7|6|-|AS,QS|JC,KD|2D,3D|5C,8C|-2C,JC
 */
class HeartsGameState : public TrickBasedGameState
{
public:
    HeartsGameState();
    void initializeGame();
    void updateGameState(QString move);
    int findWinners() const;
    QList<int> getValidNumberOfPlayers() const;
    int getTurn() const;
    QStringList findValidMoves() const;
    void printGameState() const;

private:
    /**
     * @brief Finds the player that the a given player passes to
     * @param The player that is doing the passing
     * @return The player who recieves the card
     */
    int findPlayerToPassTo(int player);
    char board[3][3];
    int playerTurn; //The player whos turn it is
    void incrementTurn();
    void deincrementTurn();
};
#endif // HEARTS_H
