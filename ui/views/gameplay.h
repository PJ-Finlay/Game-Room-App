#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "view.h"

#include <QWidget>

#include "games/game.h"

/**
 * @brief A View where the user plays a game
 */
class GamePlay : public View
{
    Q_OBJECT

public:
    /**
     * @brief Creates a GamePlay object
     * @param The game to be played
     * @param The pointer of the parent QWidget
     */
    GamePlay(Game game, QWidget* parent);

private slots:
    /**
     * @brief Slot that emits the returnToGameChooserClicked signal
     */
    void returnToGameChooser();

signals:
    /**
     * @brief Signal that the user wants to return to the menu to select a new Game
     */
    void returnToGameChooserClicked();
};

#endif // GAMEPLAY_H
