#include "gamechooserbutton.h"

GameChooserButton::GameChooserButton(Game game, QWidget* parent) : QPushButton(parent)
{
    //Assign game piv to game parameter
    this->game = game;

    //Set the text of the button to the name of the game
    this->setText(game.getName());

    //Connect the clicked signal from this button to its chooseGame slot
    QObject::connect(this,SIGNAL(clicked()),this,SLOT(chooseGame()));
}

Game GameChooserButton::getGame(){
    return this->game;
}

void GameChooserButton::chooseGame(){
    emit gameChosen(this->game);
}
