#include "game.h"

#include <QLabel>

#include "../gamestate/individual_game_states/tictactoegamestate.h" //Should be temporary

QString Game::getName() const{
    return this->name;
}

void Game::setName(QString name){
    this->name = name;
}

QWidget* Game::getGameWidget() const{
    QLabel* p = new QLabel(getName());
    return p;
}

std::shared_ptr<GameState> Game::getGameState() const
{
    std::shared_ptr<TicTacToeGameState> toReturn(new TicTacToeGameState());
    return toReturn;
}


