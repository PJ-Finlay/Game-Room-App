#include "cli.h"

#include <QString>
#include <iostream>
#include <string>
#include <QList>
#include <memory>
#include <QProcess>

#include "../gamelist.h"
#include "../gamestate/gamestate.h"

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
    clearScreen();
    cout << gameToPlay.getName().toStdString() << endl;

    //Get the GameState for the game that is being played
    std::shared_ptr<GameState> gameState = gameToPlay.getGameState();
    gameState->initializeGame();



}

void CLI::clearScreen()
{
    //Windows
    //QProcess::execute("CLS");

    //Unix
    QProcess::execute("clear");
}
