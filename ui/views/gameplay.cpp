#include "gameplay.h"

#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

#include "../widgets/pushbuttonwithid.h"

#include <QDebug>

GamePlay::GamePlay(std::shared_ptr<Game> game, QWidget* parent) : View(parent)
{
    //Initialize PIV's
    this->game = game;
    layout = new QVBoxLayout(this);
    currentWidget = new QWidget(this);
    layout->addWidget(currentWidget);
    this->setLayout(layout);

    showOptionsSelector();
}

void GamePlay::showGamePlay()
{
    this->gameState = game->getGameState();
    this->gameWidget = game->getGameWidget();

    //Initialize GUI

    QWidget* gamePlay = new QWidget(this);

    //Create button that returns user the the GameChooser view
    QPushButton* returnToGameChooserButton = new QPushButton("<-",gamePlay);

    //Set GameWidget Parent
    gameWidget->setParent(gamePlay);

    //Create the layout for Gameplay view
    QVBoxLayout* layout = new QVBoxLayout(gamePlay);

    //Add both widgets in VBoxLayout
    layout->addWidget(returnToGameChooserButton);
    layout->addWidget(gameWidget);

    //Set the layout
    gamePlay->setLayout(layout);

    //Connect clicked signal from return button to the returnToGameChooser signal
    QObject::connect(returnToGameChooserButton,SIGNAL(clicked(bool)),this,SLOT(returnToGameChooser()));
    //Connect moveEntered signal and slot
    QObject::connect(gameWidget,SIGNAL(moveEntered(QString)),this,SLOT(moveEntered(QString)));


    //Setup GameState
    gameState->initializeGame();
    gameWidget->setGameState(gameState->getGameState());
    checkForComputerPlay();

    this->layout->removeWidget(currentWidget);
    this->layout->addWidget(gamePlay);
    delete currentWidget;
    currentWidget = gamePlay;
}

void GamePlay::showOptionsSelector()
{
    this->gameState = game->getGameState();

    //Initialize GUI

    QWidget* optionsView = new QWidget(this);

    //Create button that returns user the the GameChooser view
    QPushButton* returnToGameChooserButton = new QPushButton("<-",optionsView);
    QVBoxLayout* layout = new QVBoxLayout(optionsView);
    layout->addWidget(returnToGameChooserButton);

    //Create buttons for player selection
    playerSelection = new PlayerSelection(gameState->getValidNumberOfPlayers(),optionsView);
    layout->addWidget(playerSelection);

    //Create continue button
    QPushButton* continueButton = new QPushButton("Continue",optionsView);
    layout->addWidget(continueButton);
    QObject::connect(continueButton,SIGNAL(clicked(bool)),this,SLOT(continueToGame()));

    //Set the layout
    optionsView->setLayout(layout);

    //Connect clicked signal from return button to the returnToGameChooser signal
    QObject::connect(returnToGameChooserButton,SIGNAL(clicked(bool)),this,SLOT(returnToGameChooser()));

    this->layout->removeWidget(currentWidget);
    this->layout->addWidget(optionsView);
    delete currentWidget;
    currentWidget = optionsView;
}

void GamePlay::checkForComputerPlay()
{
    int turn = gameState->getTurn();
    if(playerConfiguration.mid(turn - 1,1).compare("c") == 0 && gameState->findWinners() == -1){//If it is the computer's turn
        QString computerMove = game->getComputerPlayer()->getMoveFromGameState(gameState->getGameState());
        gameState->makeMove(computerMove);
        gameWidget->makeMove(computerMove);
        gameWidget->setGameState(gameState->getGameState());
        checkForComputerPlay();
    }
}

void GamePlay::returnToGameChooser(){
    emit returnToGameChooserClicked();
}

void GamePlay::moveEntered(QString move)
{
    if(gameState->findWinners() != -1) return;
    gameState->makeMove(move);
    gameWidget->makeMove(move);
    gameWidget->setGameState(gameState->getGameState());
    checkForComputerPlay();
}

void GamePlay::continueToGame()
{
    playerConfiguration = playerSelection->getPlayerSelection();
    showGamePlay();
}
