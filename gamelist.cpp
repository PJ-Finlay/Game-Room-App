#include "gamelist.h"

#include "games/individual_game/tictactoe.h"

GameList::GameList(){
    //QList of the Game objects that GameRoom includes
    gamesList = new QList<Game>();

    //Create all of the game objects
    Game* tictactoe = new TicTacToe();
    gamesList->append(*tictactoe);

    Game* chess = new Game();
    gamesList->append(*chess);

    Game* checkers = new Game();
    gamesList->append(*checkers);

    Game* hearts = new Game();
    gamesList->append(*hearts);

}


QList<Game>* GameList::getGameList(){
    return gamesList;
}
