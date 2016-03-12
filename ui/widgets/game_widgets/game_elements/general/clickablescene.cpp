#include "clickablescene.h"

#include <QGraphicsSceneMouseEvent>

ClickableScene::ClickableScene(QObject * parent) : QGraphicsScene(parent)
{

}

void ClickableScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QPointF p = mouseEvent->buttonDownScenePos(Qt::LeftButton);
    int x = p.x();
    int y = p.y();
    emit clicked(x,y);
}
