#include "heartstests.h"

#include <QDebug>
#include <iostream>
#include <string>

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
    bool allTestsPassed = true;

    HeartsGameState h;
    h.initializeGame();




    h.setGameState("0-R-|13|0|7|6|-|AS,QS|JC,KD|2D,3D|5C,8C|-2C,JC");
    if(h.getGameState().compare("0-R-|13|0|7|6|-|AS,QS|JC,KD|2D,3D|5C,8C|-2C,JC") != 0){
        allTestsPassed = false;
        qDebug() << "setGameState or getGameState not working correctly in TrickBasedGameState";
    }
    h.setGameState("123123990-Some Text Here-|12343|234524|23464345|68012|-|AS,QS|JC,KD|2D,3D|5C,8C|-afsdasdfasdf,Jasfdasdf,Casfdasfdsdfsdf,asdfasdfasdf,asfd");
    if(h.getGameState().compare("123123990-Some Text Here-|12343|234524|23464345|68012|-|AS,QS|JC,KD|2D,3D|5C,8C|-afsdasdfasdf,Jasfdasdf,Casfdasfdsdfsdf,asdfasdfasdf,asfd") != 0){
        allTestsPassed = false;
        qDebug() << "setGameState or getGameState not working correctly in TrickBasedGameState";
    }
    h.setGameState("0--|1|2|3|4|-|AC|JD|3C|AS|-");
    if(h.getGameState().compare("0--|1|2|3|4|-|AC|JD|3C|AS|-") != 0){
        allTestsPassed = false;
        qDebug() << "setGameState or getGameState not working correctly in TrickBasedGameState";
    }

    h.initializeGame();
    qDebug() << h.getGameState();
    std::string input;
    std::cin >> input;
    h.makeMove(QString::fromStdString(input));


    if(!allTestsPassed) qDebug() << "HeartsGameState Failed";
    return allTestsPassed;
}
