#include "gamelist.h"

#include "games/individual_game/tictactoe.h"

GameList::GameList(){
    //QList of the Game objects that GameRoom includes
    QList<Game> q;
    gamesList = q;

    //Create all of the game objects
    Game* tictactoe = new TicTacToe();
    gamesList.append(*tictactoe);
}


QList<Game> GameList::getGameList(){
    return gamesList;
}
