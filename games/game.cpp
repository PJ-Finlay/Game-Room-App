#include "game.h"

#include <QLabel>

Game::Game()
{
}

QString Game::getName() const{
    return this->name;
}

void Game::setName(QString name){
    this->name = name;
}

QWidget* Game::getGameWidget(){
    QLabel* p = new QLabel(getName());
    return p;
}
