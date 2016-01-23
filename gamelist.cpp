#include "gamelist.h"

#include <memory>

#include "games/individual_game/tictactoe.h"

std::shared_ptr<Game> GameList::getGame(int index)
{
    if(index == 0){
        std::shared_ptr<TicTacToe> ticTacToe(new TicTacToe());
        return ticTacToe;
    }else{ //Invalid Index
        std::shared_ptr<TicTacToe> ticTacToe(new TicTacToe());
        return ticTacToe;
    }
}

int GameList::numberOfGames()
{
    return 1;
}
