#ifndef TICTACTOEGAMEWIDGET_H
#define TICTACTOEGAMEWIDGET_H

#include "../../gamewidget.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QList>
#include <QVBoxLayout>

#include "../pushbuttonwithid.h"
#include "game_elements/general/clickablescene.h"


/**
 * @brief The TicTacToeGameWidget class is the GameWidget for TicTacToe, and provides a GUI for the TicTacToe Game
 */
class TicTacToeGameWidget : public GameWidget
{
    Q_OBJECT

public:
    /**
     * @brief Creates a new TicTacToeGameWidget and initializes the internal variables.
     * @param parent The parent of the TicTacToeGameWidget
     */
    explicit TicTacToeGameWidget(QWidget* parent = 0);

protected:
    /**
     * @brief This event is called when the widget is resized (including the initial sizing).
     * This redraws the entire scene with the new size.
     * This is an expensive operation, as it requires resizing an image and redrawing the existing pieces on the board.
     * @param event
     */
    void resizeEvent(QResizeEvent* event);

private:
    QVBoxLayout* layout;
    ClickableScene* scene; //The ClickableScene used to show the game
    QGraphicsView* view; // The QGraphicsView that encapsulates the ClickableScene
    QGraphicsPixmapItem* background; //The background which shows the # markings for TicTacToe
    QString gameState; //Keep on copy of the gamestate so that it can be redrawn if the window is resized
    QList<QGraphicsItem*> placedPieces; //Keep a list of the placed pieces so that they can be removed to redraw the gamestate

    /**
     * @brief Draws a piece on the board based on board coordinates
     * @param x (0-2) The X coordinate of the piece to place
     * @param y (0-2) The Y coordinate of the piece to place
     * @param isX If an X should be placed (otherwise an O is placed)
     */
    void drawPiece(int x, int y, bool isX);


public slots:
    void setGameState(QString gameState);

private slots:
    /**
     * @brief This slot should be called when the scene was clicked.
     * This method figures out which square was clicked and emits the appropriate moveEntered signal.
     * This slot should be connected to the clicked(x,y) signal of the ClickableScene
     * @param x The x coordinate (in scene coordinates of the click)
     * @param y The y coordinate (in scene coordinates of the click)
     */
    void squareClicked(int x, int y);


signals:
    void moveEntered(QString move);

};

#endif // TICTACTOEGAMEWIDGET_H
