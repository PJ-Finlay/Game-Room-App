#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "view.h"

#include <QWidget>

#include "games/game.h"
#include "ui/gamewidget.h"

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
    GamePlay(std::shared_ptr<Game> game, QWidget* parent);

private:
    std::shared_ptr<Game> game;
    std::shared_ptr<GameState> gameState;
    GameWidget* gameWidget;

private slots:
    /**
     * @brief Slot that emits the returnToGameChooserClicked signal
     */
    void returnToGameChooser();

    /**
     * @brief This should be called when a move is entered in the GameWidget
     */
    void moveEntered(QString move);

signals:
    /**
     * @brief Signal that the user wants to return to the menu to select a new Game
     */
    void returnToGameChooserClicked();
};

#endif // GAMEPLAY_H
