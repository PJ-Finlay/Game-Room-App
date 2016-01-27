#include "card.h"

Card::Card(QString id, bool acesHigh)
{
    this->id = id;
    this->acesHigh = acesHigh;
}

QString Card::getId() const
{
    return id;
}

void Card::setId(const QString &value)
{
    id = value;
}

bool Card::getAcesHigh() const
{
    return acesHigh;
}

void Card::setAcesHigh(bool value)
{
    acesHigh = value;
}

QString Card::getSuit() const
{
    return id.right(1);
}

QString Card::getValue() const
{
    return id.left(id.length() - 1);
}

int Card::getIntValue() const
{
    QString value = getValue();
    if(value.compare("J") == 0) return 11;
    if(value.compare("Q") == 0) return 12;
    if(value.compare("K") == 0) return 13;
    if(value.compare("A") == 0 && acesHigh) return 14;
    if(value.compare("A") == 0 && !acesHigh) return 1;
    else{
        return value.toInt();
    }
}

QString Card::getLongValue() const
{
    QString toReturn = getValue();
    if(toReturn.compare("J") == 0) return "Jack";
    if(toReturn.compare("Q") == 0) return "Queen";
    if(toReturn.compare("K") == 0) return "King";
    if(toReturn.compare("A") == 0) return "Ace";
    return toReturn;
}

QString Card::getLongSuit() const
{
    QString suit = getSuit();
    if(suit.compare("H") == 0) return "Hearts";
    if(suit.compare("D") == 0) return "Diamonds";
    if(suit.compare("S") == 0) return "Spades";
    if(suit.compare("C") == 0) return "Clubs";
    return "Undefined Suit";
}

QString Card::toString() const
{
    return getLongValue() + " of " + getLongSuit();
}
