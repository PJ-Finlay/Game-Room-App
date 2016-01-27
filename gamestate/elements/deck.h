#ifndef DECK_H
#define DECK_H

#include <QList>

#include "card.h"

/**
 * @brief Represents a deck of cards, where the card at index 0 is the top card in a deck sitting on a table
 */
class Deck
{
public:
    /**
     * @brief Creates a Deck based on a QList of cards
     * @param cards The QList to be used
     */
    Deck(QList<Card> cards);

    /**
     * @brief Creates an empty Deck
     */
    Deck();

    /**
     * @brief Makes a Deck based on a String preset
     * @param preset The preset to be used
     */
    Deck(QString preset);

    /**
     * @brief Get the QList of Cards in the Deck
     * @return A QList of the Cards in the deck
     */
    QList<Card> getCards() const;

    /**
     * @brief Set the QList of Cards in the Deck
     * @param value The new QList of Cards
     */
    void setCards(const QList<Card> &value);

    /**
     * @brief Adds a card to the top of the deck
     * @param toAdd The card to be added
     */
    void addCardtoTop(Card toAdd);

    /**
     * @brief Adds a Card to the bottom of the Deck
     * @param toAdd The card to be added
     */
    void addCardtoBottom(Card toAdd);

    /**
     * @brief Adds a Card to the middle of the Deck based on an index.
     * An index of 0 would place the card at the top of the deck, and an index of cards.size() would place it at the bottom of the Deck
     * @param toAdd The Card to be added
     */
    void addCardFromIndex(Card toAdd, int index);

    /**
     * @brief Gets a card from an index.
     * An index of 0 would get the card at the top of the deck, and an index of cards.size() would get it at the bottom of the Deck.
     * The Card is not removed from the Deck
     * @return The card at the index
     */
    Card getCardFromIndex(int index);


    /**
     * @brief Takes a card from an index.
     * An index of 0 would get the card at the top of the deck, and an index of cards.size() would get it at the bottom of the Deck.
     * The Card is removed from the Deck
     * @return The card at the index
     */
    Card takeCardFromIndex(int index);

    /**
     * @brief Shuffles the Deck into a random order
     */
    void shuffle();

    /**
     * @brief Returns a String representation of the Deck
     * @return A QString that displays the Deck
     */
    QString toString();







private:
    QList<Card> cards;
};

#endif // DECK_H
