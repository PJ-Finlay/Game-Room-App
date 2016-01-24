#include "gamelist.h"

#include <memory>

#include "games/individual_game/tictactoe.h"
#include "games/individual_game/checkers.h"

std::shared_ptr<Game> GameList::getGame(int index)
{
    if(index == 0){
        std::shared_ptr<TicTacToe> ticTacToe(new TicTacToe());
        return ticTacToe;
    }if(index == 1){
        std::shared_ptr<Checkers> checkers(new Checkers());
        return checkers;
    }else{ //Invalid Index
        std::shared_ptr<TicTacToe> ticTacToe(new TicTacToe());
        return ticTacToe;
    }
}

int GameList::numberOfGames()
{
    return 2;
}
