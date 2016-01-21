#include "gamelist.h"

#include "games/individual_game/tictactoe.h"

GameList::GameList(){
    //QList of the Game objects that GameRoom includes
    QList<Game> q;
    gamesList = q;

    //Create all of the game objects
    Game tictactoe;
    gamesList.append(tictactoe);
}


std::shared_ptr<QList<Game>> GameList::getGameList(){
    std::shared_ptr<QList<Game>> toReturn(&this->gamesList);
    return toReturn;
}
