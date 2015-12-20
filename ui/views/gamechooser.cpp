#include "gamechooser.h"

#include <QVBoxLayout>
#include <QList>

#include "../../gamelist.h"
#include "../../games/game.h"
#include "../widgets/gamechooserbutton.h"

GameChooser::GameChooser(QWidget *parent) : View(parent)
{
    //Layout for GameChooserView
    QVBoxLayout* layout = new QVBoxLayout();

    //Get the list of the games
    GameList* gameList = new GameList();
    QList<Game>* list = gameList->getGameList();

    //Loop through list and add each game to page as a GameChooserButton
    for (int i = 0; i < list->size(); i++) {
        Game game = list->at(i);
        GameChooserButton* button = new GameChooserButton(game,this);
        layout->addWidget(button);

        //Connect button click signal to selectGame slot
        QObject::connect(button,SIGNAL(gameChosen(Game)),this,SLOT(selectGame(Game)));
    }

    //Set layout of GameChooser
    this->setLayout(layout);
}

void GameChooser::selectGame(Game game){
    emit gameChosen(game);
}

