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
    QWidget* containerWidget = new QWidget(this);
    containerWidget->setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding));

    //Layout for GameChooserView
    QVBoxLayout* containerLayout = new QVBoxLayout(this);

    //Add a title
    QLabel* title = new QLabel("<h1>Game Room</h1>", this);
    title->setAlignment(Qt::AlignCenter);
    containerLayout->addWidget(title);

    //Loop through list and add each game to page as a GameChooserButton
    for (int i = 0; i < GameList::numberOfGames(); i++) {
        std::shared_ptr<Game> game = GameList::getGame(i);
        GameChooserButton* button = new GameChooserButton(game,this);
        button->setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding));
        containerLayout->addWidget(button);

        //Connect button click signal to selectGame slot
        QObject::connect(button,SIGNAL(gameChosen(std::shared_ptr<Game>)),this,SLOT(selectGame(std::shared_ptr<Game>)));
    }

    //Set layout of GameChooser
    containerWidget->setLayout(containerLayout);
    containerWidget->resize(500,500);
    QVBoxLayout* viewLayout = new QVBoxLayout(this);
    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setWidget(containerWidget);
    scrollArea->setBackgroundRole(QPalette::Dark);

    viewLayout->addWidget(scrollArea);
    this->setLayout(viewLayout);
}

void GameChooser::selectGame(std::shared_ptr<Game> game){
    emit gameChosen(game);
}

