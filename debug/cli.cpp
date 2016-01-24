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
    QString message = "";

    while(true){
        clearScreen();

        //Print game menu
        cout << "Game Room" << endl << endl;
        for(int i = 0; i < GameList::numberOfGames(); i++){
            cout << i << " - " << GameList::getGame(i)->getName().toStdString() << endl;
        }
        cout << message.toStdString();

        //Get user input
        int input;
        cin >> input;

        if(input >= 0 && input < GameList::numberOfGames()){
            std::shared_ptr<Game> gameToPlay = GameList::getGame(input);
            playGame(gameToPlay);
        }else{
            message += "Invalid choice\n";
        }
    }
}

void CLI::playGame(std::shared_ptr<Game> gameToPlay)
{
    clearScreen();
    cout << "What player do you want to play as?" << endl << endl << "0 - All" << endl << "n - Specific Player" << endl;
    int playAs;
    cin >> playAs;

    //Get the GameState for the game that is being played
    std::shared_ptr<GameState> gameState = gameToPlay->getGameState();
    //Get the ComputerPlayer for the game that is being played
    std::shared_ptr<ComputerPlayer> computerPlayer = gameToPlay->getComputerPlayer();

    gameState->initializeGame();
    gameState->enableUndo();

    QString message;
    while(gameState->findWinners() == -1){
        //Print Current State
        clearScreen();
        cout << gameToPlay->getName().toStdString() << endl;
        gameState->printGameState();
        cout << endl;
        cout << message.toStdString();
        message = "";

        if(gameState->getTurn() == playAs || playAs == 0){
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
    cout << gameToPlay->getName().toStdString() << endl;
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
            return;
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
