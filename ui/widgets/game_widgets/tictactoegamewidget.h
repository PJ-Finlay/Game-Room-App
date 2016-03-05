#ifndef TICTACTOEGAMEWIDGET_H
#define TICTACTOEGAMEWIDGET_H

#include "../../gamewidget.h"

#include <QPushButton>

#include "../pushbuttonwithid.h"

class TicTacToeGameWidget : public GameWidget
{
    Q_OBJECT

public:
    explicit TicTacToeGameWidget(QWidget* parent = 0);

private:
    PushButtonWithId* buttons[3][3];


public slots:
    void setGameState(QString gameState);

private slots:
    void squareClicked(QString id);

};

#endif // TICTACTOEGAMEWIDGET_H
