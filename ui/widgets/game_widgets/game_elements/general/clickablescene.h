#ifndef TICTACTOEQGRAPHICSSCENE_H
#define TICTACTOEQGRAPHICSSCENE_H

#include <QGraphicsScene>

class ClickableScene : public QGraphicsScene
{
    Q_OBJECT

public:
    ClickableScene(QObject * parent = 0);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);

signals:
    void clicked(int x, int y);
};

#endif // TICTACTOEQGRAPHICSSCENE_H
