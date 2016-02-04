#ifndef GAMECHOOSERBUTTON_H
#define GAMECHOOSERBUTTON_H

#include <QPushButton>

#include "../../games/game.h"

/**
 * @brief A button that is used to represent a game that can be played. By clicking on it, it emits a signal with its enclosed game.
 */
class GameChooserButton : public QPushButton
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a GameChooserButton
     * @param The game that this button represents
     * @param parent
     */
    GameChooserButton(std::shared_ptr<Game> game, QWidget* parent);

    /**
     * @brief Gets the Game object that the GameChooserButton represents
     * @return The game object that was selected
     */
    std::shared_ptr<Game> getGame();

private:
    std::shared_ptr<Game> game;

private slots:
    /**
     * @brief Slot that emits gameChosen signal with the stored Game
     */
    void chooseGame();

signals:
    /**
     * @brief Signals that the user has clicked on the button and selected a game
     * @param g The game that has been chosen
     */
    void gameChosen(std::shared_ptr<Game> game);

};

#endif // GAMECHOOSERBUTTON_H
