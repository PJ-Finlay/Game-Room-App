#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QWidget>

#include "games/game.h"

class GamePlay : public QWidget
{
    Q_OBJECT
public:
    GamePlay(Game game, QWidget* parent);

public slots:
    void returnToGameChooser();

signals:
    void returnToGameChooserClicked();
};

#endif // GAMEPLAY_H
