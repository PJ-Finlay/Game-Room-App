#include "game.h"

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
