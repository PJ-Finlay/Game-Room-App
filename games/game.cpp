#include "game.h"

#include <QLabel>

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
    return 0;
}

