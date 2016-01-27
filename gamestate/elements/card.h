#ifndef CARD_H
#define CARD_H

#include <QString>

/**
 * @brief Represents a card in the format Queen of Spades = QS, where all letters are capital.
 * This class also provides methods to access information about the card
 */
class Card
{
public:
    /**
     * @brief Create a new Card object based on a QString id. Ids are in the format valuesuit so the king of spades would be KS, and the 10 of hearts would be 10H.
     * Letters should be capitol
     *
     * @param id The id of the card to be created
     * @param acesHigh If aces should be considered higher than kings, otherwise they will be considered below 2's
     */
    Card(QString id, bool acesHigh = false);

    /**
     * @brief Gets the Id of the card
     * @return The id of the card
     */
    QString getId() const;

    /**
     * @brief Sets the Id of the card
     * @param value The new ID of the card
     */
    void setId(const QString &value);

    /**
     * @brief Finds out if aces are high in this card
     * @return If aces are high
     */
    bool getAcesHigh() const;

    /**
     * @brief Set whether aces should be high or not
     * @param The new value of acesHigh
     */
    void setAcesHigh(bool value);

    /**
     * @brief Gets the suit of a card
     * @return The suit of the card. For example for the King of Hearts this would return H
     */
    QString getSuit();

    /**
     * @brief Gets the value of the card.
     * @return The value fo the card. For example for the King of Hearts this would return K, and the 10 of Spades would return 10
     */
    QString getValue();

    /**
     * @brief Gets an int value for the card from 1-14. Numbers return their own value so the 2 of Spades would return 2.
     * Face cards return their int value so J->11 , Q->12, K->13.
     * If aces are high A->14, if they are not A->1
     * @return The int value of the card
     */
    int getIntValue();

    /**
     * @brief Gets the long suit of a card
     * @return The long suit of a card. For example for the King of Spades this would return "Spades"
     */
    QString getLongSuit();

    /**
     * @brief Gets the long value of card.
     * @return The long value of a card for example for the King of Spades it would return "King", and for the 10 of Spades it would return "10"
     */
    QString getLongValue();

    /**
     * @brief Gets the String value of a card
     * @return The QString value of a card. For the King of Spades this would return "King of Spades"
     */
    QString toString();

private:
    QString id;
    bool acesHigh;
};

#endif // CARD_H
