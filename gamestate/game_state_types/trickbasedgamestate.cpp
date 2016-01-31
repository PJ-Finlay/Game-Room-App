#include "trickbasedgamestate.h"

#include <QDebug>



TrickBasedGameState::TrickBasedGameState() : GameState()
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



void TrickBasedGameState::clearGameState()
{
    setMode(0);
    setOtherInfo("");
    setPlayerScore(1,0);
    setPlayerScore(2,0);
    setPlayerScore(3,0);
    setPlayerScore(4,0);
    dealHand();
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
    clearMoveRecord();
}

void TrickBasedGameState::printGameState() const
{
    qDebug() << "1)" << getPlayerScore(1);
    qDebug() << "2)" << getPlayerScore(2);
    qDebug() << "3)" << getPlayerScore(3);
    qDebug() << "4)" << getPlayerScore(4);
}

QList<QString> TrickBasedGameState::getPreTrickMoves() const
{
    QList<QString> toReturn = getMoveRecord();
    int index = toReturn.indexOf(QString("*"));
    if(index == -1) return QList<QString>();
    return toReturn.mid(0,index);
}

QList<QString> TrickBasedGameState::getTrickMoves() const
{
    QList<QString> toReturn = getMoveRecord();
    int index = toReturn.indexOf(QString("*"));
    if(index == -1) return toReturn;
    int secondIndex = toReturn.lastIndexOf(QString("*"));
    return toReturn.mid(index,secondIndex-index);
}

QList<QString> TrickBasedGameState::getPostTrickMoves() const
{
    QList<QString> toReturn = getMoveRecord();
    int index = toReturn.lastIndexOf(QString("*"));
    if(index == -1) return QList<QString>();
    return toReturn.mid(index);
}

int TrickBasedGameState::findWinnerOfTrick(QString trumpSuit, QList<QString> cards)
{
    int indexOfBestCard = 0;
    bool trumpCardFound = false;
    Card bestCard = Card(cards.at(0));
    for(int i = 0; i < cards.size(); i++){
        Card currentCard = Card(cards.at(i));
        if(currentCard.getSuit().compare(trumpSuit) == 0){
            if(!trumpCardFound || currentCard.getIntValue() > bestCard.getIntValue()){
                bestCard = currentCard;
                indexOfBestCard = i;
            }
            trumpCardFound = true;
        }
        if(currentCard.getSuit().compare(trumpSuit) != 0 && ! trumpCardFound){
            if(currentCard.getIntValue() > bestCard.getIntValue()){
                bestCard = currentCard;
                indexOfBestCard = i;
            }
        }
    }
    return indexOfBestCard;
}

QList<QList<QString>> TrickBasedGameState::getPlayerHands() const
{
    QList<QList<QString>> toReturn = getStartingHands();
    QList<QString> moves = getTrickMoves();
    for(int i = 0; i < moves.length(); i++){ //Go through each move
        QString currentMove = moves.at(i);
        for(int j = 0; j < toReturn.size(); i++){ //Loop through each set of cards
            int index = toReturn.at(i).indexOf(currentMove);
            if(index != -1){
                QList<QString> newList = toReturn.at(i);
                newList.removeAt(i);
                toReturn.replace(i,newList);
                break;
            }
        }
    }
    return toReturn;
}

bool TrickBasedGameState::donePlayingTricks() const
{
    QList<QList<QString>> hands = getPlayerHands();
    for(int i = 0; i < hands.size(); i++){
        if(hands.at(i).size() > 0) return false;
    }
    return true;
}

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

void TrickBasedGameState::setGameState(QString value)
{
    //Get Mode
    setMode(value.left(value.indexOf("-")).toInt());
    value = value.right(value.length() - value.indexOf("-") - 1);

    //Get other info
    setOtherInfo(value.left(value.indexOf("-")));
    value = value.right(value.length() - value.indexOf("-") - 2);

    //Get player scores
    for(int i = 0; i < 4; i++){
        setPlayerScore(i + 1 , value.left(value.indexOf("|")).toInt());
        value = value.right(value.length() - value.indexOf("|") - 1);
    }
    value = value.right(value.length() - value.indexOf("-") - 1);

    //Get starting hands
    QList<QList<QString>> startingHands;
    for(int i = 0; i < 4; i++){
        QList<QString> hand;
        if(i != 3) hand.append(value.left(value.indexOf("|")));
        if(i == 3) hand.append(value.left(value.indexOf("-") - 1));
        value = value.right(value.length() - value.indexOf("|") - 1);
        startingHands.append(hand);
    }
    setStartingHands(startingHands);
    value = value.right(value.length() - value.indexOf("-") - 1);

    //Get Move Record
    clearMoveRecord();
    bool keepLooping = true;
    while(keepLooping){
        if(value.indexOf(",") != -1){
            addToMoveRecord(value.left(value.indexOf(",")));
            value = value.right(value.length() - value.indexOf(",") - 1);
        }else{
            addToMoveRecord(value);
            keepLooping = false;
        }
    }


}
