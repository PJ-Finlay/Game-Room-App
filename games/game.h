#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QWidget>
#include <memory>

#include "../gamestate/gamestate.h"
#include "../ai/computer_players/computerplayer.h"
#include "../ui/gamewidget.h"

/**
 * @brief The superclass for every game
 */
class Game
{
public:
    /**
     * @brief Gets the name of the Game
     * @return The name of the game
     */
    QString getName() const;

    /**
     * @brief Sets the name of the Game
     * @param name The name to be set
     */
    void setName(QString name);

    /**
     * @brief Gets the widget that plays this game. If this method is not redefined in a subclass.
     * @return The widget that plays the represented game
     */
    virtual GameWidget* getGameWidget() const;

    /**
     * @brief Gets a shared_ptr to the GameState that represents the game
     * @return The gamestate
     */
    virtual std::shared_ptr<GameState> getGameState() const = 0;

    /**
     * @brief Gets a shared_ptr to the ComputerPlayer for a given game
     * @return The shared_ptr to the Computer Player
     */
    virtual std::shared_ptr<ComputerPlayer> getComputerPlayer() const = 0;

private:
    QString name;
};

#endif // GAME_H
