#ifndef GAMELIST_H
#define GAMELIST_H

#include "games/game.h"

#include <QList>
#include <memory>


/**
 * @brief A class that returns list of games. It has a method for getting a QList of games, and may later support a method for getting different lists (for a lite version).
 */
class GameList
{
public:
    /**
     * @brief Returns the standard list of games
     * @return All of the currently supported Games
     */
    static std::shared_ptr<QList<Game>> getGameList();
};

#endif // GAMELIST_H
