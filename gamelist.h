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
     * @brief Returns a std::shared_ptr to the game from an index, if an invalid index is given it returns TicTacToe
     * @return The requested game pointer
     */
    static std::shared_ptr<Game> getGame(int index);

    /**
     * @brief Gets the number of games that are currently supported. For example if this method returns 3 there are games at the indexes 0,1,2.
     * @return
     */
    static int numberOfGames();
};

#endif // GAMELIST_H
