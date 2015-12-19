#ifndef GAMECHOOSERBUTTON_H
#define GAMECHOOSERBUTTON_H

#include <QPushButton>

#include "../../games/game.h"

class GameChooserButton : public QPushButton
{
    Q_OBJECT
public:
    GameChooserButton(Game game, QWidget* parent = 0);
    Game getGame();

private:
    Game game;

public slots:
    void chooseGame();

signals:
    void gameChosen(Game g);

};

#endif // GAMECHOOSERBUTTON_H
