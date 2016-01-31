#ifndef HEARTS_H
#define HEARTS_H

#include "../game_state_types/trickbasedgamestate.h"

/**
 * @brief Represents a Hearts game state.
 * Internally the game is represented as the same QString that it uses to interface externally.
 * Game State String Format:
 * Mode(Passing-Tricks)-TypeOfPassingThisHand(R/L/A,N)-Player1Score|Player2Score|Player3Score|Player4Score-Player1StartingHand(,Seperated)|Player2Hand|Player3Hand|Player4Hand-Coma seperated move record
 * Move notation:
 * Playing Card - CardID
 * Example (With reduced cards for simplicity):
 * 13|0|7|6-AS,QS|JC,KD|2D,3D|5C,8C-2C,JC
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
    char board[3][3];
    int playerTurn; //The player whos turn it is
    void incrementTurn();
    void deincrementTurn();
};
#endif // HEARTS_H
