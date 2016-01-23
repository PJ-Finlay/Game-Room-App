#ifndef GAMECHOOSER_H
#define GAMECHOOSER_H

#include "view.h"

#include <QWidget>

#include "games/game.h"

/**
 * @brief A View that allows the user to select the game that they want to play
 */
class GameChooser : public View
{
    Q_OBJECT

public:
    /**
     * @brief Creates a GameChooser object
     * @param The pointer of the parent QWidget
     */
    GameChooser(QWidget* parent);

signals:
    /**
     * @brief Signals that a game has been chosen, and passes the game that has been chosen
     * @param game The game that has been selected
     */
    void gameChosen(Game game);

private slots:
    /**
     * @brief Slot that emits a signal that a game has been chosen
     * @param The game that will be signaled as chosen
     */
    void selectGame(Game game);
};

#endif // GAMECHOOSER_H
