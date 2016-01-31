#include "testdirectory.h"

#include <QDebug>

//Games
#include "gametests/tictactoetests.h"
#include "gametests/checkerstests.h"
#include "gametests/trickbasedgametests.h"
#include "gametests/heartstests.h"

//AI Algorithms
#include "aialgorithm/aialgorithmtester.h"

//Other Tests
#include "othertest/othertests.h"

void TestDirectory::allTests()
{
    bool allTestsPassed = true;

    if(!TestDirectory::allGames()) allTestsPassed = false;

    if(!TestDirectory::allAIAlgorithms()) allTestsPassed = false;

    if(!TestDirectory::otherTests()) allTestsPassed = false;

    if(allTestsPassed){
        qDebug() << "All Tests Passed";
    }
}

bool TestDirectory::allGames()
{
    bool allTestsPassed = true;

    if(!TicTacToeTests::allTests()) allTestsPassed = false;
    if(!CheckersTests::allTests()) allTestsPassed = false;
    if(!HeartsTests::allTests()) allTestsPassed = false;
    if(!TrickBasedGameTests::allTests()) allTestsPassed = false;

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

bool TestDirectory::otherTests()
{
    bool allTestsPassed = true;

    if(!OtherTests::allTests()) allTestsPassed = false;

    if(!allTestsPassed) qDebug() << "Other tests failed";

    return allTestsPassed;
}
