#include "othertests.h"

#include <QDebug>
#include <iostream>

#include "../../../gamestate/elements/card.h"
#include "../../../gamestate/elements/deck.h"

using namespace std;

bool OtherTests::allTests(){
    bool allTestsPassed = true;

    if(!testDeck()) allTestsPassed = false;
    if(!testCard()) allTestsPassed = false;

    if(!allTestsPassed) qDebug() << "Other Tests Failed";

    return allTestsPassed;
}

bool OtherTests::testCard()
{
    bool allTestsPassed = true;
    Card c("10H");

    if(c.toString().compare("10 of Hearts") != 0){
        qDebug() << "Constructor or toString not working";
        allTestsPassed = false;
    }
    c = Card("KS");
    if(c.toString().compare("King of Spades") != 0){
        qDebug() << "Constructor or toString not working";
        allTestsPassed = false;
    }
    c = Card("KS",true);
    if(c.getAcesHigh() != true){
        qDebug() << "Constructor or getAcesHigh not working";
        allTestsPassed = false;
    }
    c = Card("KS");
    if(c.getAcesHigh() != false){
        qDebug() << "Constructor or getAcesHigh not working";
        allTestsPassed = false;
    }
    c.setId("KH");
    if(c.getId().compare("KH") != 0){
        qDebug() << "setId or getId not working";
        allTestsPassed = false;
    }
    c.setId("2C");
    if(c.getId().compare("2C") != 0){
        qDebug() << "setId or getId not working";
        allTestsPassed = false;
    }
    c.setAcesHigh(true);
    if(c.getAcesHigh() != true){
        qDebug() << "setAcesHigh or getAcesHigh not working";
        allTestsPassed = false;
    }
    c.setAcesHigh(false);
    if(c.getAcesHigh() != false){
        qDebug() << "setAcesHigh or getAcesHigh not working";
        allTestsPassed = false;
    }
    c.setId("KH");
    if(c.getSuit().compare("H") != 0){
        qDebug() << "getSuit not working";
        allTestsPassed = false;
    }
    c.setId("10S");
    if(c.getSuit().compare("S") != 0){
        qDebug() << "getSuit not working";
        allTestsPassed = false;
    }
    c.setId("KH");
    if(c.getValue().compare("K") != 0){
        qDebug() << "getValue not working";
        allTestsPassed = false;
    }
    c.setId("10C");
    if(c.getValue().compare("10") != 0){
        qDebug() << "getValue not working";
        allTestsPassed = false;
    }
    c.setId("KH");
    if(c.getIntValue() != 13){
        qDebug() << "getIntValue not working";
        allTestsPassed = false;
    }
    c.setId("2C");
    if(c.getIntValue() != 2){
        qDebug() << "getIntValue not working";
        allTestsPassed = false;
    }
    c.setId("10S");
    if(c.getIntValue() != 10){
        qDebug() << "getIntValue not working";
        allTestsPassed = false;
    }
    c.setId("AS");
    c.setAcesHigh(true);
    if(c.getIntValue() != 14){
        qDebug() << "getIntValue not working";
        allTestsPassed = false;
    }
    c.setId("AS");
    c.setAcesHigh(false);
    if(c.getIntValue() != 1){
        qDebug() << "getIntValue not working";
        allTestsPassed = false;
    }

    if(!allTestsPassed) qDebug() << "Card Failed";

    return allTestsPassed;
}

bool OtherTests::testDeck()
{
    bool allTestsPassed = true;

    //Currently no unit tests


    if(!allTestsPassed) qDebug() << "Deck Failed";
    return allTestsPassed;
}
