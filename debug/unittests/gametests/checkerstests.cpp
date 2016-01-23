#include "checkerstests.h"

#include <QDebug>

#include "../../../gamestate/individual_game_states/checkersgamestate.h"

bool CheckersTests::allTests()
{
    bool allTestsPassed = true;

    if(!testCheckersGameState()) allTestsPassed = false;

    if(!allTestsPassed) qDebug() << "Checkers Failed";

    return allTestsPassed;
}

bool CheckersTests::testCheckersGameState()
{
    bool allTestsPassed = true;

    CheckersGameState g;

    if(g.getTurn() != 1){
        allTestsPassed = false;
        qDebug() << "Getting or setting turn not working correctly";
    }

    g.initializeGame();
    if(g.getGameState().compare("________________________________________________________________") !=0 ){
        allTestsPassed = false;
        qDebug() << "Initialize Game or getGameState not working correctly";
    }

    return allTestsPassed;
}
