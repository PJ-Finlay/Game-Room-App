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
    QString moveEntered();

public slots:
    /**
     * @brief Instructs the GameWidget to show that a move has been mad. This method is included so that an animation can be
     * shown between moves, and to improve efficiency.
     * @param move The move to be shown
     */
    void makeMove(QString move);

    /**
     * @brief Displays a given game state graphically
     * @param gameState The GameState to be displayed
     */
    void setGameState(QString gameState);
};

#endif // GAMEWIDGET_H
