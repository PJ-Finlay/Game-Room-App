#ifndef GAMECHOOSER_H
#define GAMECHOOSER_H

#include <QWidget>

#include "games/game.h"

class GameChooser : public QWidget
{
    Q_OBJECT
public:
    GameChooser(QWidget* parent);

signals:
    void gameChosen(Game game);

public slots:
    void selectGame(Game game);
};

#endif // GAMECHOOSER_H
