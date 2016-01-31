#include "deck.h"

#include <stdlib.h>

#include <QDebug>

Deck::Deck(QList<Card> cards)
{
    this->cards = cards;
}

Deck::Deck()
{
    this->cards = QList<Card>();
}

Deck::Deck(QString preset)
{
    this->cards = QList<Card>();
    if(preset.compare("Standard") == 0){
        for(int s = 0; s < 4; s++){
            for(int v = 1; v <= 13; v++){
                QString suit;
                QString value;
                if(s == 0) suit = "H";
                if(s == 1) suit = "D";
                if(s == 2) suit = "C";
                if(s == 3) suit = "S";

                value = QString::number(v);
                if(v == 1) value = "A";
                if(v == 13) value = "K";
                if(v == 12) value = "Q";
                if(v == 11) value = "J";


                addCardtoTop(Card(value+suit, true));
            }
        }
    }
}

QList<Card> Deck::getCards() const
{
    return cards;
}

void Deck::setCards(const QList<Card> &value)
{
    cards = value;
}

void Deck::addCardtoTop(Card toAdd)
{
    cards.prepend(toAdd);
}

void Deck::addCardtoBottom(Card toAdd)
{
    cards.append(toAdd);
}

void Deck::addCardFromIndex(Card toAdd, int index)
{
    cards.insert(index,toAdd);
}

Card Deck::getCardFromIndex(int index)
{
    return cards.at(index);
}

Card Deck::takeCardFromIndex(int index)
{
    return cards.takeAt(index);
}

Card Deck::takeCardFromTop()
{
    return takeCardFromIndex(0);
}

void Deck::shuffle()
{
    srand(time(NULL));
    for(int i = 0; i < cards.size(); i++){
        double r = ((double) rand() / (RAND_MAX));
        int index = (int) (r * (cards.size() - i));
        cards.swap(i,index);
    }
}

QString Deck::toString()
{
    QString toReturn;
    for(int i = 0; i < cards.size(); i++){
        toReturn.append(cards.at(i).toString());
        toReturn.append("\n");
    }
    return toReturn;
}
