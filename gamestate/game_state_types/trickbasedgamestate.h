#ifndef TRICKBASEDGAMESTATE_H
#define TRICKBASEDGAMESTATE_H

#include "../gamestate.h"

#include <QList>

#include "../elements/deck.h"

/**
 * @brief Represents a trick based game
 * Internally the game is represented as the same QString that it uses to interface externally.
 * Game State String Format:
 * Mode(Integer)(Game Dependant)-OtherInfo(Dealer/Pass Direction)-Player1Score|Player2Score|Player3Score|Player4Score-Player1StartingHand(,Seperated)|Player2Hand|Player3Hand|Player4Hand-Coma seperated move record
 * Move notation:
 * Playing Card - CardID
 * Passing Cards - CardIDs (Comma seperated)
 * Example (With reduced cards for simplicity):
 * 0-R-|13|0|7|6|-AS,QS|JC,KD|2D,3D|5C,8C-2C,JC
 */
class TrickBasedGameState
{
public:
    TrickBasedGameState();

    void initializeGame();

    QString getGameState() const;


    int getMode() const;
    void setMode(int value);

    QString getOtherInfo() const;
    void setOtherInfo(const QString &value);

    int getPlayerScore(int player) const;
    void setPlayerScore(int player,int value);

    QList<QList<QString> > getStartingHands() const;
    void setStartingHands(const QList<QList<QString> > &value);


    QList<QString> getMoveRecord() const;
    void setMoveRecord(const QList<QString> &value);
    void addToMoveRecord(QString moveToAdd);
    void clearMoveRecord();

    void dealHand();

private:
    Deck deck;
    QString gameState;
    int mode;
    QString otherInfo;
    QList<int> playerScores;//Scores moved 1 0->player1score
    QList<QList<QString>> startingHands; //Scores moved 1 0->player1score
    QList<QString> moveRecord;
};

#endif // TRICKBASEDGAMESTATE_H
