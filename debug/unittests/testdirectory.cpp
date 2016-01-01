#include "testdirectory.h"

#include <QDebug>

#include "gamestatestests.h"
#include "aialgorithmtester.h"

void TestDirectory::allTests()
{
    bool allTestsPassed = true;
    if(!TestDirectory::allGameStates()){
        allTestsPassed = false;
        qDebug() << "GameStates Failed";
    }
    if(!TestDirectory::allAIAlgorithms()){
        allTestsPassed = false;
        qDebug() << "AI Algorithms Failed";
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

bool TestDirectory::allAIAlgorithms()
{
    bool allTestsPassed = true;
    if(!AIAlgorithmTester::testMinimax()){
        allTestsPassed = false;
        qDebug() << "Minimax Failed";
    }
    return allTestsPassed;
}
