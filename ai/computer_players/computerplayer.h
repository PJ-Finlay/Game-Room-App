#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include <QString>

/**
 * @brief Represents a computer player for a game. Computer players for individual games inherit from this class.
 * This class supports variable difficulty, and can be interfaced with in two ways.
 * The first way to interface with this class is with the getMoveFromGameState(QString method), which takes an entire gamestate, and returns the chosen move.
 * The second way is to set the game state of the ComputerPlayer, and then gradually change the game state with addMoveToGameState(), and getMoveFromMove().
 * This allows the class to internally run more efficiently by not having to parse the game state again for every new move, and potentially maintain multi-move strategies.
 */
class ComputerPlayer
{
public:
    /**
     * @brief Creates a new ComputerPlayer object
     * @param difficulty The difficulty from 0-1 that the computer should play at, with 0 being random and 1 being full difficulty.
     */
    ComputerPlayer(double difficulty = 1);

    /**
     * @brief Gets the difficulty of the ComputerPlayer object
     * @return The current difficulty
     */
    double getDifficulty() const;

    /**
     * @brief Sets the difficulty of the ComputerPlayer object
     * @param difficulty the new difficulty of the ComputerPlayer object
     */
    void setDifficulty(double difficulty);

    /**
     * @brief Takes a game state string and returns the computer players move
     * @param gamestate The game state that the computer should base its moves on
     * @return The move picked by the computer player.
     */
    virtual QString getMoveFromGameState(QString gamestate) const = 0;


private:
    double difficulty;
};

#endif // COMPUTERPLAYER_H
