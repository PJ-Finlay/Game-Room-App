#include "gameplay.h"

#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QMessageBox>

#include "../widgets/pushbuttonwithid.h"

#include <QDebug>

GamePlay::GamePlay(std::shared_ptr<Game> game, QWidget* parent) : View(parent)
{
    //Initialize PIV's
    this->game = game;
    layout = new QStackedLayout(this);
    this->setLayout(layout);
    gamePlayIndex = -1;
    optionsSelectorIndex = -1;
    gameOverIndex = -1;


    showOptionsSelector();
}

void GamePlay::showGamePlay()
{
    playerConfiguration = playerSelection->getPlayerSelection();
    if(gamePlayIndex < 0){

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

        gamePlayIndex = this->layout->addWidget(gamePlay);

        //Makes it not a "Normal View"
        this->setIsNormalView(false);
    }
    this->layout->setCurrentIndex(gamePlayIndex);
}

void GamePlay::resetBoard()
{
    gameState->initializeGame();
    gameWidget->setGameState(gameState->getGameState());
    showGamePlay();
}

void GamePlay::showOptionsSelector()
{
    if(optionsSelectorIndex < 0){
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
        QObject::connect(continueButton,SIGNAL(clicked(bool)),this,SLOT(showGamePlay()));

        //Set the layout
        optionsView->setLayout(layout);

        //Connect clicked signal from return button to the returnToGameChooser signal
        QObject::connect(returnToGameChooserButton,SIGNAL(clicked(bool)),this,SLOT(returnToGameChooser()));

        optionsSelectorIndex = this->layout->addWidget(optionsView);

        //Makes it a "Normal View"
        this->setIsNormalView(true);
    }
    this->layout->setCurrentIndex(optionsSelectorIndex);
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

void GamePlay::showGameOver()
{
    if(gameOverIndex < 0){
        QWidget* gameOverWidget = new QWidget(this);
        QVBoxLayout* layout = new QVBoxLayout(gameOverWidget);

        QString titleText = "Player " + QString::number(gameState->findWinners()) + " Won";
        if(gameState->findWinners() == 0) titleText = "There Was A Tie";
        QLabel* title = new QLabel(titleText,gameOverWidget);
        layout->addWidget(title);

        QPushButton* viewGame = new QPushButton("View Game", gameOverWidget);
        QObject::connect(viewGame,SIGNAL(clicked(bool)),this,SLOT(showGamePlay()));
        layout->addWidget(viewGame);

        QPushButton* playAgain = new QPushButton("Play Again", gameOverWidget);
        QObject::connect(playAgain,SIGNAL(clicked(bool)),this,SLOT(resetBoard()));
        layout->addWidget(playAgain);

        QPushButton* mainMenu = new QPushButton("Return to Main Menu", gameOverWidget);
        QObject::connect(mainMenu,SIGNAL(clicked(bool)),this,SLOT(returnToGameChooser()));
        layout->addWidget(mainMenu);


        gameOverWidget->setLayout(layout);

        gameOverIndex = this->layout->addWidget(gameOverWidget);
    }
    this->layout->setCurrentIndex(gameOverIndex);
}

void GamePlay::returnToGameChooser(){
    emit returnToGameChooserClicked();
}

void GamePlay::moveEntered(QString move)
{
    if(gameState->isValidMove(move) && gameState->findWinners() < 0){
        gameState->makeMove(move);
        gameWidget->makeMove(move);
        gameWidget->setGameState(gameState->getGameState());
        checkForComputerPlay();
        if(gameState->findWinners() != -1){
            showGameOver();
        }
    }
}

