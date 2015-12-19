#include "game.h"

#include <QPushButton>

Game::Game()
{
    this->setName("Game Name");
}

QString Game::getName(){
    return this->name;
}

void Game::setName(QString name){
    this->name = name;
}

QWidget* Game::getGameWidget(){
    QPushButton* p = new QPushButton();
    return p;
}
