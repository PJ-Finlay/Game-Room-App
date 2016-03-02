#include "gameplay.h"

#include <QPushButton>
#include <QVBoxLayout>

GamePlay::GamePlay(std::shared_ptr<Game> game, QWidget* parent) : View(parent)
{
    //Create button that returns user the the GameChooser view
    QPushButton* returnToGameChooserButton = new QPushButton("<-");

    //Get the gameWidget from the game
    std::shared_ptr<GameWidget> gameWidget = game->getGameWidget();
    gameWidget->setParent(this);

    //Create the layout for Gameplay view
    QVBoxLayout* layout = new QVBoxLayout(this);

    //Add both widgets in VBoxLayout
    layout->addWidget(returnToGameChooserButton);
    layout->addWidget(gameWidget.get());

    //Set the layout
    this->setLayout(layout);

    //Connect clicked signal from return button to the returnToGameChooser signal
    QObject::connect(returnToGameChooserButton,SIGNAL(clicked(bool)),this,SLOT(returnToGameChooser()));

}

void GamePlay::returnToGameChooser(){
    emit returnToGameChooserClicked();
}
