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

