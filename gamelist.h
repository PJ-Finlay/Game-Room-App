#ifndef GAMELIST_H
#define GAMELIST_H

#include "games/game.h"

#include <QList>

class GameList
{
public:
    explicit GameList();
    QList<Game>* getGameList();

private:
    QList<Game>* gamesList;
};

#endif // GAMELIST_H
