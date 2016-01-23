#include "checkerstests.h"

#include <QDebug>

bool CheckersTests::allTests()
{
    bool allTestsPassed = true;

    if(!testCheckersGameState()) allTestsPassed = false;

    if(!allTestsPassed) qDebug() << "Checkers Failed";

    return allTestsPassed;
}

bool CheckersTests::testCheckersGameState()
{
    return true;
}
