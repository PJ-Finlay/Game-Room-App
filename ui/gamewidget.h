#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QString>
#include <QWidget>

/**
 * @brief This class provides a graphical front end for a game.
 */
class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = 0);

signals:
    /**
     * @brief Signals that a move has been entered in the GUI
     * @return The move that was entered
     */
    void moveEntered(QString move);

public slots:
    /**
     * @brief Instructs the GameWidget to show that a move has been mad. This method is included so that an animation can be
     * shown between moves, and to improve efficiency.
     * THIS METHOD SHOULD NOT BE CALLED ALONE.
     * Instead you should call makeMove, then setGameState so that GameWidget's without animations do not need to implement this method.
     * @param move The move to be shown
     */
    virtual void makeMove(QString move);

    /**
     * @brief Displays a given game state graphically
     * @param gameState The GameState to be displayed
     */
    virtual void setGameState(QString gameState);
};

#endif // GAMEWIDGET_H
