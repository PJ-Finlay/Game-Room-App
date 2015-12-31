#include "testdirectory.h"

#include <QDebug>

#include "gamestatestests.h"

void TestDirectory::allTests()
{
    bool allTestsPassed = true;
    if(!TestDirectory::allGameStates()){
        allTestsPassed = false;
        qDebug() << "GameStates Failed";
    }

    if(allTestsPassed){
        qDebug() << "All Tests Passed";
    }
}

bool TestDirectory::allGameStates()
{
    bool allTestsPassed = true;

    if(!GameStatesTests::testTicTacToeGameState()){
        allTestsPassed = false;
        qDebug() << "TicTacToeGameState Failed";
    }

    return allTestsPassed;
}
