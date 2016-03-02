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

std::shared_ptr<GameWidget> Game::getGameWidget() const{
    GameWidget* gameWidget;
    std::shared_ptr<GameWidget> toReturn(gameWidget);
    QLabel* p = new QLabel(getName(),gameWidget);
    return toReturn;
}


