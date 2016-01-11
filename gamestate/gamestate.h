#ifndef GAMERULLES_H
#define GAMERULLES_H

#include <QString>
#include <QStringList>

/**
 * @brief A class that provides an interface to all of the logic behind a game, in addition to storing and manipulating a game state.
 * It is intended that every game has a class that inherits from this class that describes its rules.
 * This interface is intended to both provide a uniform way to get information about the rules both for user facing code, and for use by the computer player.
 * Boards and moves can be represented by QStrings, and players by ints starting at 1 (1,2,3,4,.....) with player 1 being the player that plays first.
 * It is intended that classes that inherit from this will not use strings internally to represent game states, but will instead use more efficient data structures that can be converted to strings to interface with other classes in a uniform way.
 * Since game states will be used when efficiency is important game state objects do not perform checks to make sure the parameters they are given are valid, and can perform unpredictably if given invalid arameters
 * Also the string representation of a move does not need to include information about the player making the move, unless it is a game that permits moves to be made out of turn.
 *
*/
class GameState
{
public:
    /**
     * @brief Creates a new GameState object
     */
    GameState();

    /**
     * @brief Create a new default game, and set it as the game state of the GameRules object
     */
    virtual void initializeGame() = 0;

    /**
     * @brief Gets the current game state of the object
     * @return
     */
    virtual QString getGameState() const = 0;

    /**
     * @brief Set the game state of the object
     * @param gameState The new game state of the object
     */
    virtual void setGameState(QString gameState) = 0;

    /**
     * @brief Finds out if a provided move is valid
     * @param move The move that will be checked
     * @return The validity of the move.
     */
    virtual bool isValidMove(QString move) const;

    /**
     * @brief Updates the game state of the object based on a move.
     * Use makeMove instead of this method if undo functionality might be required.
     * @param move the move that will modify the game state
     */
    virtual void updateGameState(QString move) = 0;

    /**
     * @brief Makes a move. This involves adding to the undo record if valid, and then calling updateGameState
     * This is the appropriate way to make a move if undo functionality is required.
     * @param The move to be made
     */
    void makeMove(QString move);

    /**
     * @brief Returns a QList of ints that contains all of the valid number of players for that game.
     * @return A QList of all of the valid number of players
     */
    virtual QList<int> getValidNumberOfPlayers() const = 0;

    /**
     * @brief Finds which players turn it is.
     * @return The player whose turn it is
     */
    virtual int getTurn() const = 0;


    /**
     * @brief Finds out if this object has undo enabled.
     * Undo is a potential resource waste, and is intended for use with user facing games and not games used by ComputerPlayers.
     * @return The value of undoEnabled
     */
    bool getUndoEnabled() const;

    /**
     * @brief Starts saving past game states for undo
     */
    void enableUndo();

    /**
     * @brief Takes back the most recent move on the game. If undo is enabled, or there are no moves to undo this does nothing.
     */
    void undoMove();

    /**
     * @brief Finds the number of saved undo states
     * @return The number of undos remaining
     */
    int undosRemaining() const;

    /**
     * @brief Find if there are any winners to the game
     * @return Any potential winners. -1 is no game ending condition, 0 is a tie, and a positive integer is the number of the winning player.
     */
    virtual int findWinners() const = 0;

    /**
     * @brief Finds a QList of all of the valid moves that can be made at the current game state
     * @return A QList of the valid moves that can be made
     */
    virtual QStringList findValidMoves() const = 0;

    /**
     * @brief Makes an estimate of the competitive position of the player. This is intended for use by a computer player
     * -1 means losing is certain, 1 means winning certain. The closer the value to 1, the better the position of the player.
     * If this is not implemented (for a game like tic tac toe) then by default this proxies the findWinners method.
     * @param player The player who's competative position is being evaluated
     * @return The players competative position
     */
    virtual double competitivePosition(int player) const;

    /**
     * @brief Prints the game state in a format useful for debugging purposes using qDebug()
     */
    virtual void printGameState() const;





private:
    bool undoEnabled;
    QList<QString> undoRecord;
};

#endif // GAMERULLES_H
