#include "heartstests.h"

#include <QDebug>

#include "../../../gamestate/individual_game_states/heartsgamestate.h"

bool HeartsTests::allTests()
{
    bool allTestsPassed = true;

    if(!testHeartsGameState()) allTestsPassed = false;

    if(!allTestsPassed) qDebug() << "Hearts Tests Failed";

    return allTestsPassed;
}

bool HeartsTests::testHeartsGameState()
{
    return true;
}
