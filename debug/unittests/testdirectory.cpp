#include "testdirectory.h"

#include <QDebug>

#include "tictactoetests.h"
#include "aialgorithmtester.h"

void TestDirectory::allTests()
{
    bool allTestsPassed = true;

    if(!TestDirectory::allGames()) allTestsPassed = false;

    if(!TestDirectory::allAIAlgorithms()) allTestsPassed = false;

    if(allTestsPassed){
        qDebug() << "All Tests Passed";
    }
}

bool TestDirectory::allGames()
{
    bool allTestsPassed = true;

    if(!TicTacToeTests::allTests()) allTestsPassed = false;

    if(!allTestsPassed) qDebug() << "Games Failed";

    return allTestsPassed;
}

bool TestDirectory::allAIAlgorithms()
{
    bool allTestsPassed = true;

    if(!AIAlgorithmTester::testMinimax()) allTestsPassed = false;

    if(!allTestsPassed) qDebug() << "AI Algorithms Failed";

    return allTestsPassed;
}
