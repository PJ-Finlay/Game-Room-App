#ifndef TRICKBASEDGAMESTATE_H
#define TRICKBASEDGAMESTATE_H

#include "../gamestate.h"

#include <QList>

#include "../elements/deck.h"

/**
 * @brief Represents a trick based game
 * Game State String Format:
 * Mode(Integer)(Game Dependant)-OtherInfo(Dealer/Pass Direction)-Player1Score|Player2Score|Player3Score|Player4Score-Player1StartingHand(,Seperated)|Player2Hand|Player3Hand|Player4Hand-Coma seperated move record
 * If there are moves made before or after the trick taking part of the game these are seperated by a * move.
 * Note: If you use a * move you must include a * move on both sides of the trick moves
 * Note: The starting hands refer to the hands that existed at the start of trick taking play
 * Note: Player 1 should be considered to be at the bottom of the table with the numbers increasing going clockwise around the table.
 * Example (With reduced cards for simplicity):
 * 0-R-|13|0|7|6|-|AS,QS|JC,KD|2D,3D|5C,8C|-2C,JC
 */
class TrickBasedGameState : public GameState
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

    /**
     * @brief Prints the scores, the hands, and the cards played that trick
     */
    virtual void printGameState() const;

    /**
     * @brief Get all of the moves that come before the * move, and an empty QList<QString> if there is never a * move
     * @return A QList<QString> of the pre moves
     */
    QList<QString> getPreTrickMoves() const;

    /**
     * @brief Get the moves between the two * moves and all of the moves if there are no * moves returns all of the moves
     * @return The trick making moves
     */
    QList<QString> getTrickMoves() const;

    /**
     * @brief Get all of the moves that come after the * move, and an empty QList<QString> if there is never a * move
     * @return A QList<QString> of the pre moves
     */
    QList<QString> getPostTrickMoves() const;

    /**
     * @brief Finds the winner of a trick
     * @param trumpSuit The suit that acts as trump for this trick
     * @param cards The cards that are being evaluated
     * @return The index of the card that won the trick
     */
    static int findWinnerOfTrick(QString trumpSuit, QList<QString> cards);

    /**
     * @brief Get the hands of each of all of the players
     * @return A QList of QLists of QStrings which represent a card
     */
    QList<QList<QString>> getPlayerHands() const;

    /**
     * @brief Determines if all of the player's hands are empty
     * @return If all of the player's hands are empty
     */
    bool donePlayingTricks() const;

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
