#include "gamechooser.h"

#include <QVBoxLayout>
#include <QScrollArea>
#include <QList>
#include <QLabel>
#include <memory>

#include "../../gamelist.h"
#include "../../games/game.h"
#include "../widgets/gamechooserbutton.h"

GameChooser::GameChooser(QWidget *parent) : View(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    //Add a title
    QLabel* title = new QLabel("Game Room", this);
    title->setAlignment(Qt::AlignCenter);
    layout->addWidget(title);

    //Loop through list and add each game to page as a GameChooserButton
    for (int i = 0; i < GameList::numberOfGames(); i++) {
        std::shared_ptr<Game> game = GameList::getGame(i);
        GameChooserButton* button = new GameChooserButton(game,this);
        layout->addWidget(button);

        //Connect button click signal to selectGame slot
        QObject::connect(button,SIGNAL(gameChosen(std::shared_ptr<Game>)),this,SLOT(selectGame(std::shared_ptr<Game>)));
    }

    //Set layout of GameChooser
    this->setLayout(layout);
}

void GameChooser::selectGame(std::shared_ptr<Game> game){
    emit gameChosen(game);
}

