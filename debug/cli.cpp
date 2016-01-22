#include "cli.h"

#include <QString>
#include <iostream>
#include <string>
#include <QList>
#include <memory>
#include <QProcess>

#include "../gamelist.h"
#include "../gamestate/gamestate.h"
#include "../ai/computer_players/computerplayer.h"

using namespace std;

void CLI::play()
{

    //Get Game List
    GameList gameListObject;
    std::shared_ptr<QList<Game>> gameList = gameListObject.getGameList();

    //Print game menu
    cout << "Game Room" << endl << endl;
    for(int i = 0; i < gameList->size(); i++){
        cout << i << " - " << gameList->at(i).getName().toStdString() << endl;
    }

    //Get user input
    int input;
    cin >> input;

    Game gameToPlay = gameList->at(input);
    playGame(gameToPlay);

}

void CLI::playGame(Game gameToPlay)
{
    //Get the GameState for the game that is being played
    std::shared_ptr<GameState> gameState = gameToPlay.getGameState();
    //Get the ComputerPlayer for the game that is being played
    //std::shared_ptr<ComputerPlayer> computerPlayer = gameToPlay.getComputerPlayer();

    gameState->initializeGame();
    gameState->enableUndo();

    QString message;
    while(gameState->findWinners() == -1){
        //Print Current State
        clearScreen();
        cout << gameToPlay.getName().toStdString() << endl << endl;
        gameState->printGameState();
        cout << message.toStdString();
        message = "";

        //if(gameState->getTurn() == 1){
            string input;
            cin >> input;
            if(gameState->isValidMove(QString::fromStdString(input))){
                gameState->makeMove(QString::fromStdString(input));
            }else{
                message.append("Invalid Move\n");
            }
        //}else{
        //    gameState->makeMove(computerPlayer->getMoveFromGameState(gameState->getGameState()));
       // }
    }

}

void CLI::clearScreen()
{
    //Windows
    //QProcess::execute("CLS");

    //Unix
    QProcess::execute("clear");
}
