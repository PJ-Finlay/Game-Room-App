#ifndef TICTACTOEGAMEWIDGET_H
#define TICTACTOEGAMEWIDGET_H

#include "../../gamewidget.h"

#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "../pushbuttonwithid.h"
#include "game_elements/general/clickablescene.h"

class TicTacToeGameWidget : public GameWidget
{
    Q_OBJECT

public:
    explicit TicTacToeGameWidget(QWidget* parent = 0);

protected:
    void resizeEvent(QResizeEvent* event);

private:
    ClickableScene* scene;
    QGraphicsView* view;
    QGraphicsPixmapItem* background;
    QString gameState;

    void drawPiece(int x, int y, bool isX);


public slots:
    void setGameState(QString gameState);

private slots:
    void squareClicked(int x, int y);


signals:
    void moveEntered(QString move);

};

#endif // TICTACTOEGAMEWIDGET_H
