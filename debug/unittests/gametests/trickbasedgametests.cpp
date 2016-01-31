#include "trickbasedgametests.h"

#include <QDebug>

#include "../../../gamestate/game_state_types/trickbasedgamestate.h"

bool TrickBasedGameTests::allTests()
{
    bool allTestsPassed = true;

    if(!testTrickBasedGameState()) allTestsPassed = false;

    if(!allTestsPassed) qDebug() << "TrickBasedGameTests Failed";

    return allTestsPassed;
}

bool TrickBasedGameTests::testTrickBasedGameState()
{
    bool allTestsPassed = true;

    TrickBasedGameState t;
    t.initializeGame();
    qDebug() << t.getGameState();



    if(!allTestsPassed) qDebug() << "TrickBasedGameState Failed";

    return allTestsPassed;
}
