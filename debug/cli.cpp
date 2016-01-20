#include "cli.h"

#include <QDebug>
#include <QString>
#include <iostream>
#include <string>
#include <QList>
#include <memory>

#include "../gamelist.h"

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

    //Get Selection from user
    int selection;
    cin >> selection;
    Game gameToPlay = gameList->at(selection);

    //Play that game
    playGame(gameToPlay);
}

void CLI::playGame(Game gameToPlay)
{

}
