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
    while(true){
        clearScreen();
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
}

void CLI::playGame(Game gameToPlay)
{
    //Get the GameState for the game that is being played
    std::shared_ptr<GameState> gameState = gameToPlay.getGameState();
    //Get the ComputerPlayer for the game that is being played
    std::shared_ptr<ComputerPlayer> computerPlayer = gameToPlay.getComputerPlayer();

    gameState->initializeGame();
    gameState->enableUndo();

    QString message;
    while(gameState->findWinners() == -1){
        //Print Current State
        clearScreen();
        cout << gameToPlay.getName().toStdString() << endl;
        gameState->printGameState();
        cout << endl;
        cout << message.toStdString();
        message = "";

        if(gameState->getTurn() == 1){
            string input;
            cin >> input;
            if(gameState->isValidMove(QString::fromStdString(input))){
                gameState->makeMove(QString::fromStdString(input));
            }else{
                message.append("Invalid Move\n");
            }
        }else{
            gameState->makeMove(computerPlayer->getMoveFromGameState(gameState->getGameState()));
        }
    }
    //The game has now ended
    clearScreen();
    cout << gameToPlay.getName().toStdString() << endl;
    gameState->printGameState();
    int winner = gameState->findWinners();
    if(winner == 0) cout << "There was a tie" << endl;
    if(winner > 0) cout << "Player " << winner << " won" << endl;

    cout << endl << "a - Play again" << endl << "m - Return to menu" << endl;

    bool validInput = false;
    while(!validInput){
        string input;
        cin >> input;

        //This is a memory leak, but it should be small, and this is for debugging
        if(input.compare("a") == 0){
            playGame(gameToPlay);
            validInput = true;
        }
        if(input.compare("m") == 0){
            play();
            validInput = true;
        }
        return;
    }

}

void CLI::clearScreen()
{
    //Windows
    //QProcess::execute("CLS");

    //Unix
    QProcess::execute("clear");
}
