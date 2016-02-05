#include "gamechooserbutton.h"

#include <QLabel>
#include <QVBoxLayout>

GameChooserButton::GameChooserButton(std::shared_ptr<Game> game, QWidget* parent) : QPushButton(parent)
{
    //Create the layout for the button
    QVBoxLayout* layout = new QVBoxLayout(this);

    //Assign game piv to game parameter
    this->game = game;

    //Construct the text fo the button
    QString name = "<h2>";
    name.append(game->getName());
    name.append("</h2>");

    //Put the text in a QLabel
    QLabel* title = new QLabel(name, this);
    title->setAlignment(Qt::AlignCenter);

    //Add QLabel to layout and set the layout
    layout->addWidget(title);
    this->setLayout(layout);

    //Connect the clicked signal from this button to its chooseGame slot
    QObject::connect(this,SIGNAL(clicked()),this,SLOT(chooseGame()));
}

std::shared_ptr<Game> GameChooserButton::getGame(){
    return this->game;
}

void GameChooserButton::chooseGame(){
    emit gameChosen(this->game);
}
