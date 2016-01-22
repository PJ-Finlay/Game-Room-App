#include "gamelist.h"

#include <memory>

#include "games/individual_game/tictactoe.h"

std::shared_ptr<QList<Game>> GameList::getGameList(){
    //Create the QList to Return
    std::shared_ptr<QList<Game>> toReturn(new QList<Game>());

    //Add all games to the list
    std::shared_ptr<TicTacToe> ticTacToe(new TicTacToe());
    toReturn->append(*ticTacToe);

    //Return the QList
    return toReturn;
}
