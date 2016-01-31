#ifndef TRICKBASEDGAMESTATE_H
#define TRICKBASEDGAMESTATE_H

#include "../gamestate.h"

#include <QList>

#include "../elements/deck.h"

/**
 * @brief Represents a trick based game
 * Internally the game is represented as the same QString that it uses to interface externally.
 * Game State String Format:
 * Mode(Integer)(Game Dependant)-OtherInfo(Dealer/Pass Direction)-Player1Score|Player2Score|Player3Score|Player4Score-Player1StartingHand(,Seperated)|Player2Hand|Player3Hand|Player4Hand-Coma seperated move record
 * Move notation:
 * Playing Card - CardID
 * Passing Cards - CardIDs (| seperated)
 * Example (With reduced cards for simplicity):
 * 0-R-|13|0|7|6|-|AS,QS|JC,KD|2D,3D|5C,8C|-2C,JC
 */
class TrickBasedGameState : GameState
{
public:
    /**
     * @brief Creates a new TrickBasedGameState
     */
    TrickBasedGameState();

    /**
     * @brief Clears the current game state
     */
    void clearGameState();

    /**
     * @brief Gets the current QString representation of the GameState
     * @return The QString representation of the current GameState
     */
    QString getGameState() const;

    /**
     * @brief Sets the value of the GameState
     * @param value The new value to be set
     */
    void setGameState(QString value);

    /**
     * @brief Gets the current mode that the game is in (passing/tricktaking/etc)
     * @return The current mode
     */
    int getMode() const;

    /**
     * @brief Sets the game mode (passing/tricktaking/etc)
     * @param value The new mode to be used
     */
    void setMode(int value);

    /**
     * @brief Get the other info that is being stored
     * @return The other information that is being stored
     */
    QString getOtherInfo() const;

    /**
     * @brief Sets the value of other info
     * @param value The value to be set
     */
    void setOtherInfo(const QString &value);

    /**
     * @brief Gets the score of a player
     * @param The player to get the score of
     * @return The score of that player
     */
    int getPlayerScore(int player) const;

    /**
     * @brief Set the score of a player
     * @param The player whose score will be set
     * @param value The value that will be set
     */
    void setPlayerScore(int player,int value);

    /**
     * @brief Get the starting hand
     * @return A QList of QLists of QStrings that represent each player's starting hand
     */
    QList<QList<QString>> getStartingHands() const;

    /**
     * @brief Set the starting hands
     * @param value The value to be set
     */
    void setStartingHands(const QList<QList<QString> > &value);

    /**
     * @brief Get the move record for this hand
     * @return The move record
     */
    QList<QString> getMoveRecord() const;

    /**
     * @brief Set the move record for this hand
     * @param value The new move record
     */
    void setMoveRecord(const QList<QString> &value);

    /**
     * @brief Add a move to the move record
     * @param moveToAdd The move to be added
     */
    void addToMoveRecord(QString moveToAdd);

    /**
     * @brief Clear the move record
     */
    void clearMoveRecord();

    /**
     * @brief Clears the current move record and 13 random cards to each player
     */
    void dealHand();

private:
    Deck deck;
    QString gameState;
    int mode;
    QString otherInfo;
    QList<int> playerScores;//Scores moved 1 0->player1score
    QList<QList<QString>> startingHands; //Hands moved 1 0->player1score
    QList<QString> moveRecord;
};

#endif // TRICKBASEDGAMESTATE_H
