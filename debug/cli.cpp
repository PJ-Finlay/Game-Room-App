#include "cli.h"

#include <QDebug>
#include <QString>
#include <iostream>
#include <string>
#include <QList>

#include "../gamelist.h"
#include "../games/game.h"

using namespace std;

void CLI::play()
{
    //Get Game List
    GameList gameListObject;
    QList<Game> gameList = gameListObject.getGameList();

    //Print game menu
    cout << "Game Room" << endl << endl;
    for(int i = 0; i < gameList.size(); i++){
        cout << i << " - " << gameList.at(i).getName().toStdString() << endl;
    }

    //Get Selection from user
    int selection;
    cin >> selection;

    cout << selection;
}
