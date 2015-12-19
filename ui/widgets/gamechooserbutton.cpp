#include "gamechooserbutton.h"

#include <QDebug>

GameChooserButton::GameChooserButton(Game game, QWidget* parent) : QPushButton(parent)
{
    this->game = game;
    this->setText(game.getName());
    QObject::connect(this,SIGNAL(clicked()),this,SLOT(chooseGame()));
}

Game GameChooserButton::getGame(){
    return this->game;
}

void GameChooserButton::chooseGame(){
    emit gameChosen(this->game);
}
