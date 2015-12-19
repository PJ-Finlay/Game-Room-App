#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QWidget>

#include "games/game.h"

class GamePlay : public QWidget
{
public:
    GamePlay(Game game, QWidget* parent);
};

#endif // GAMEPLAY_H
