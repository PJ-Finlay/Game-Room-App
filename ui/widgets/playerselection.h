#ifndef PLAYERSELECTION_H
#define PLAYERSELECTION_H

#include <QWidget>
#include <QVBoxLayout>

#include "pushbuttonwithid.h"

class PlayerSelection : public QWidget
{
    Q_OBJECT
public:
    explicit PlayerSelection(QList<int> validPlayers, QWidget *parent = 0);
    /**
     * @brief Gets a QString that shows the arrangement of players the user has selected.
     * Each character of the string represents a player where h means a human player and c means a computer player.
     * The string "hccc" would mean a game with a single human player & 3 computer players.
     * @return
     */
    QString getPlayerSelection();

private:
    int numberOfPlayers;
    QList<PushButtonWithId*> numberOfPlayersButtons;
    QList<PushButtonWithId*> typeOfPlayersButtons;
    QHBoxLayout* typeOfPlayersLayout;
    QWidget* typeOfPlayersWidget;

    void addTypeOfPlayerButton();
    void updateTypeOfPlayerButton(int index);

private slots:
    void numberOfPlayersSelectionMade(QString selection);
    void typeOfPlayerChange(QString selection);
};

#endif // PLAYERSELECTION_H
