#include "gamechooser.h"

#include <QObject>
#include <QVBoxLayout>
#include <QPushButton>
#include <QList>

#include "../../gamelist.h"
#include "../../games/game.h"

GameChooser::GameChooser(QWidget *parent) : QWidget(parent)
{
    //Layout for GameChooserView
    QVBoxLayout* layout = new QVBoxLayout();

    //Get the list of the games
    GameList* gameList = new GameList();
    QList<Game>* list = gameList->getGameList();

    //Loop through list and add each game to page
    for (int i = 0; i < list->size(); i++) {
        Game game = list->at(i);
        QString name = game.getName();
        QPushButton* button = new QPushButton(name,this);
        layout->addWidget(button);

        //Connect button click signal to selectGame slot
        QObject::connect(button,SIGNAL(clicked()),this,SLOT(selectGame()));
    }

    //Set layout of GameChooser
    this->setLayout(layout);
}

void GameChooser::selectGame(){
    emit gameChosen();
}

