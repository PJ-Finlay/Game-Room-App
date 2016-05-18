#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "view.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QStackedLayout>

#include "games/game.h"
#include "ui/gamewidget.h"
#include "../widgets/playerselection.h"

/**
 * @brief A View where the user selects options for a game and plays it plays a game
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
    static const int movePause = 1200; //The minimum time that the computer player will take to make its move

    std::shared_ptr<Game> game; //The game that is being played
    std::shared_ptr<GameState> gameState; //The gamestate that goes with the game that is being played
    GameWidget* gameWidget; //The GameWidget for the game that is being played
    PlayerSelection* playerSelection; //The widget in the options selector view to choose # & type of players
    QString playerConfiguration; //The stored value of the player configuration
    QStackedLayout* layout; //The layout for the widget

    //These are the indexes of each of the widgets that can be shown in the layout
    int gamePlayIndex; // -1 if not created
    int optionsSelectorIndex; // -1 if not created
    int gameOverIndex; // -1 if not created

    /**
     * @brief Shows the options selector widget
     */
    void showOptionsSelector();

    /**
     * @brief Shows the game over widget
     */
    void showGameOver();

    /**
     * @brief Checks the gamestate to see if it is the computer player's turn, and makes a move if it is.
     */
    void checkForComputerPlay();

private slots:
    /**
     * @brief Slot that emits the returnToGameChooserClicked signal
     */
    void returnToGameChooser();

    /**
     * @brief This should be called when a move is entered in the GameWidget.
     * If the move entered is not valid it is ignored
     */
    void moveEntered(QString move);

    /**
     * @brief Calling this slot will show the Gamewidget
     */
    void showGamePlay();

    /**
     * @brief This slot calls gameState->initializeGame() & sets the gamestate of the gamewidget to the new game state
     */
    void resetBoard();

signals:
    /**
     * @brief Signal that the user wants to return to the menu to select a new Game
     */
    void returnToGameChooserClicked();
};

#endif // GAMEPLAY_H
