#ifndef TICTACTOEQGRAPHICSSCENE_H
#define TICTACTOEQGRAPHICSSCENE_H

#include <QGraphicsScene>

/**
 * @brief A utility class that allows you to route the coordinates of a click from the reimplemented mousePressEvent method of QGraphicsScene to a signal.
 * ClickableScene inherits from QGraphicsScene with the only difference being that when it is clicked it emits a signal of the coordinates of the click.
 * It uses Qt::LeftButton to check for the click so this will not register right/middle clicks.
 */
class ClickableScene : public QGraphicsScene
{
    Q_OBJECT

public:
    /**
     * @brief Creates a new ClickableScene
     * @param parent The parent QObject
     */
    ClickableScene(QObject * parent = 0);

protected:
    /**
     * @brief Emits the clicked signal with the x & y parameters from the QGraphicsSceneMouseEvent
     * @param mouseEvent The mouse event to be used
     */
    void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);

signals:
    /**
     * @brief This signal is emitted when the QGraphicsScene is clicked
     * @param x The X coordinate (in scene coordinates of the click)
     * @param y The Y coordinate (in scene coordinates of the click)
     */
    void clicked(int x, int y);
};

#endif // TICTACTOEQGRAPHICSSCENE_H
