#include "game.h"

#include <QLabel>

#include "../gamestate/individual_game_states/tictactoegamestate.h" //Should be temporary
#include "../ai/computer_players/tictactoecomputerplayer.h" //Should be temporary

QString Game::getName() const{
    return this->name;
}

void Game::setName(QString name){
    this->name = name;
}

GameWidget* Game::getGameWidget() const{
    GameWidget* toReturn = new GameWidget();
    QLabel* lbl = new QLabel(getName(),toReturn);
    return toReturn;
}


