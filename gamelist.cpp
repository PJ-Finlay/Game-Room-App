#include "gamelist.h"

GameList::GameList(){
    //QList of the Game objects that GameRoom includes
    gamesList = new QList<Game>();

    //Create all of the game objects
    Game* chess = new Game("Chess");
    gamesList->append(*chess);

    Game* checkers = new Game("Checkers");
    gamesList->append(*checkers);

    Game* hearts = new Game("Hearts");
    gamesList->append(*hearts);

}


QList<Game>* GameList::getGameList(){
    return gamesList;
}
