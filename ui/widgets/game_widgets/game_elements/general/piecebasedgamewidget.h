#ifndef PIECEBASEDGAMEWIDGET_H
#define PIECEBASEDGAMEWIDGET_H

#include "../../../../gamewidget.h"

#include <QGraphicsView>
#include <QDebug>
#include <QVBoxLayout>
#include <QResizeEvent>

#include "clickablescene.h"
#include "piece.h"

/**
 * @brief The PieceBasedGameWidget class provides a interface with a QGraphicsScene that is more useful for creating piece
 * based games than the normal QGraphicsScene methods. This class organizes the scene into pieces and then provides methods
 * to place and remove pieces.
 */

class PieceBasedGameWidget : public GameWidget
{
   Q_OBJECT

public:
    /**
     * @brief Create a new PieceBasedGameWidget object
     * @param parent The parent QWidget
     */
    PieceBasedGameWidget(QWidget* parent = 0);

    /**
     * @brief Sets the background of the QGraphicsScene that is being used.
     * @param pixmap The pixmap that will be used as the background
     */
    void setBackground(QPixmap pixmap);

    /**
     * @brief Adds a new piece to be displays but does not re render the canvas
     * @param newPiece The piece to be added
     */
    void addPiece(Piece newPiece);

    /**
     * @brief Clears all of the pieces on the board
     */
    void clearPieces();

    /**
     * @brief Removes a piece from the scene based on it index in the placedPieces list
     * @param index The index of the piece to be removed
     */
    void removePiece(int index);

    /**
     * @brief Gets a QList of the placed QGraphicsItems pieces
     * @return The QList of QGraphicsItems
     */
    QList<Piece> getPlacedPieces() const;

    /**
     * @brief Re renders all of the pieces in the placed pieces list
     */
    void renderPieces();

private:
    QVBoxLayout* layout;
    ClickableScene* scene; //The ClickableScene used to show the game
    QGraphicsView* view; // The QGraphicsView that encapsulates the ClickableScene
    QPixmap background; //Scene Background
    QString gameState; //Keep on copy of the gamestate so that it can be redrawn if the window is resized
    QList<Piece> placedPieces; //Keep a list of the placed pieces so that they can be removed to redraw the gamestate


    void resizeEvent(QResizeEvent *event);


signals:
    /**
     * @brief This signal is emitted when a click is registered on the board.
     * @param x The x coordinate of the click in relative coordinates
     * @param y The y coordinate of the click in relative coordinates
     */
    void boardClicked(double x, double y);

private slots:
    /**
     * @brief This slot is connected to the clicked signal of the ClickableScene. It converts that signal to relative coordinates,
     * then it emits the boardClicked signal.
     * @param x The x coordinate of the click
     * @param y The y coordinate of the click
    */
    void sceneClicked(int x, int y);

};

#endif // PIECEBASEDGAMEWIDGET_H
