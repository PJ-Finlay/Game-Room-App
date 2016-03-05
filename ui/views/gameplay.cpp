#include "gameplay.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

GamePlay::GamePlay(std::shared_ptr<Game> game, QWidget* parent) : View(parent)
{
    //Initialize PIV's
    this->game = game;
    this->gameState = game->getGameState();
    this->gameWidget = game->getGameWidget();

    //Initialize GUI

    //Create button that returns user the the GameChooser view
    QPushButton* returnToGameChooserButton = new QPushButton("<-");

    //Set GameWidget Parent
    gameWidget->setParent(this);

    //Create the layout for Gameplay view
    QVBoxLayout* layout = new QVBoxLayout(this);

    //Add both widgets in VBoxLayout
    layout->addWidget(returnToGameChooserButton);
    layout->addWidget(gameWidget);

    //Set the layout
    this->setLayout(layout);

    //Connect clicked signal from return button to the returnToGameChooser signal
    QObject::connect(returnToGameChooserButton,SIGNAL(clicked(bool)),this,SLOT(returnToGameChooser()));
    //Connect moveEntered signal and slot
    QObject::connect(gameWidget,SIGNAL(moveEntered(QString)),this,SLOT(moveEntered(QString)));


    //Setup GameState
    gameState->initializeGame();
    gameWidget->setGameState(gameState->getGameState());

}

void GamePlay::returnToGameChooser(){
    emit returnToGameChooserClicked();
}

void GamePlay::moveEntered(QString move)
{
    gameState->makeMove(move);
    gameWidget->setGameState(gameState->getGameState());
}
