#ifndef PLAYERSELECTION_H
#define PLAYERSELECTION_H

#include <QWidget>
#include <QVBoxLayout>

#include "pushbuttonwithid.h"

/**
 * @brief The PlayerSelection class is a widget that allows the user to select the number and type of player that they want in their game.
 * It takes a QList of the valid number of players and gives the user a group of buttons to select the number of players.
 * As the user changes the number of buttons it allows them to also decide on what type of player they are (computer/human).
 */
class PlayerSelection : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Create a new PlayerSelection object based on a list of the number of valid players
     * @param validPlayers What is a valid number of players for a game
     * @param parent The parent QWidget
     */
    explicit PlayerSelection(QList<int> validPlayers, QWidget *parent = 0);

    /**
     * @brief Gets a QString that shows the arrangement of players the user has selected.
     * Each character of the string represents a player where h means a human player and c means a computer player.
     * The string "hccc" would mean a game with a single human player & 3 computer players.
     * @return
     */
    QString getPlayerSelection();

private:
    int numberOfPlayers; //The current selection of the number of players
    QList<PushButtonWithId*> numberOfPlayersButtons; //The buttons for selecting the number of players
    QList<PushButtonWithId*> typeOfPlayersButtons; //The buttons for selecting the type of player
    QHBoxLayout* typeOfPlayersLayout; //The layout for the typeOfPlayersWidget
    QWidget* typeOfPlayersWidget; //A widget that allows the user to select the type of players

    /**
     * @brief Adds a new type of player button
     */
    void addTypeOfPlayerButton();

    /**
     * @brief Checks if a button is checked and updates the text on the button to reflect if that is a human / computer player
     * @param index The index of the button to be checked
     */
    void updateTypeOfPlayerButton(int index);

private slots:
    /**
     * @brief This slot should be called if the numberOfPlayers is changed.
     * This slot resets the type of players buttons to have the right number of buttons.
     * @param selection
     */
    void numberOfPlayersSelectionMade(QString selection);

    /**
     * @brief This slot should be called if a type of player button is clicked.
     * It calls the updateTypeOfPlayerButton method
     * @param selection The index of the button that was clicked.
     */
    void typeOfPlayerChange(QString selection);
};

#endif // PLAYERSELECTION_H
