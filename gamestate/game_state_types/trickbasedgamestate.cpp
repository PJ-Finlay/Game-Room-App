#include "trickbasedgamestate.h"

#include <QDebug>



TrickBasedGameState::TrickBasedGameState()
{
    gameState = "";

    mode = 0;

    otherInfo = "";

    playerScores = QList<int>();
    playerScores.append(0);
    playerScores.append(0);
    playerScores.append(0);
    playerScores.append(0);

    startingHands = QList<QList<QString>>();
    startingHands.append(QList<QList<QString>>());
    startingHands.append(QList<QList<QString>>());
    startingHands.append(QList<QList<QString>>());
    startingHands.append(QList<QList<QString>>());

    moveRecord = QList<QString>();

}

int TrickBasedGameState::getMode() const
{
    return mode;
}

void TrickBasedGameState::setMode(int value)
{
    mode = value;
}

QString TrickBasedGameState::getOtherInfo() const
{
    return otherInfo;
}

void TrickBasedGameState::setOtherInfo(const QString &value)
{
    otherInfo = value;
}

int TrickBasedGameState::getPlayerScore(int player) const
{
    return playerScores.at(player - 1);
}

void TrickBasedGameState::setPlayerScore(int player, int value)
{
    playerScores.replace(player - 1, value);
}

QList<QList<QString> > TrickBasedGameState::getStartingHands() const
{
    return startingHands;
}

void TrickBasedGameState::setStartingHands(const QList<QList<QString> > &value)
{
    startingHands = value;
}

QList<QString> TrickBasedGameState::getMoveRecord() const
{
    return moveRecord;
}

void TrickBasedGameState::setMoveRecord(const QList<QString> &value)
{
    moveRecord = value;
}

void TrickBasedGameState::addToMoveRecord(QString moveToAdd)
{
    moveRecord.append(moveToAdd);
}

void TrickBasedGameState::clearMoveRecord()
{
    moveRecord.clear();
}

void TrickBasedGameState::dealHand()
{
    deck = Deck("Standard");
    deck.shuffle();
    startingHands.clear();
    for(int i = 0; i < 4; i++){
        QList<QString> hand;
        for(int j = 0; j < 13; j++){
            hand.append(deck.takeCardFromTop().getId());
        }
        startingHands.append(hand);
    }
}


void TrickBasedGameState::initializeGame()
{
    setMode(0);
    setOtherInfo("R");
    setPlayerScore(1,0);
    setPlayerScore(2,0);
    setPlayerScore(3,0);
    setPlayerScore(4,0);
    dealHand();
}

//0-R-|13|0|7|6|-AS,QS|JC,KD|2D,3D|5C,8C-2C,JC
QString TrickBasedGameState::getGameState() const
{
    QString toReturn;
    //Mode
    toReturn.append(QString::number(getMode()));
    toReturn.append("-");
    //Scores
    toReturn.append(getOtherInfo() + "-|");
    for(int i = 0; i < playerScores.size(); i++){
        toReturn.append(QString::number(playerScores.at(i)));
        toReturn.append("|");

    }
    toReturn.append("-");
    //Starting Hands
    for(int i = 0; i < startingHands.size(); i++){
        QList<QString> hand = startingHands.at(i);
        for(int j = 0; j < hand.size(); j++){
            toReturn.append(hand.at(j));
            if(j != hand.size() - 1) toReturn.append(",");
        }
        toReturn.append("|");
    }
    toReturn.append("-");
    //Move Record
    for(int i = 0; i < moveRecord.size(); i++){
        toReturn.append(moveRecord.at(i));
        if(i != moveRecord.size() -1) toReturn.append(",");
    }
    return toReturn;
}
