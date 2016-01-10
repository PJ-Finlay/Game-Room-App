#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QWidget>

/**
 * @brief The superclass for every game
 */
class Game
{
public:
    /**
     * @brief Constructs a Game object
     */
    Game();

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
     * @brief Gets the widget that plays this game
     * @return The widget that plays the represented game
     */
    QWidget* getGameWidget();

private:
    QString name;

};

#endif // GAME_H
