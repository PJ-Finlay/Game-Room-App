#include "tictactoegamewidget.h"

#include <QGridLayout>
#include <QDebug>

TicTacToeGameWidget::TicTacToeGameWidget(QWidget* parent) : GameWidget(parent)
{
    QGridLayout* layout = new QGridLayout(this);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            QString buttonId = QString::number(j) + QString::number(2 - i);
            PushButtonWithId* btn = new PushButtonWithId(buttonId," ",this);
            buttons[j][2 - i] = btn;
            layout->addWidget(btn,i,j);
            QObject::connect(btn,SIGNAL(clicked(QString)),this,SLOT(squareClicked(QString)));
        }
    }
    this->setLayout(layout);
}

void TicTacToeGameWidget::setGameState(QString gameState)
{
    for(int i = 0; i < 9; i++){ //loop through the gameState string's characters
        buttons[i % 3][2 - (i / 3)]->setText(gameState.at(i));
    }
}

void TicTacToeGameWidget::squareClicked(QString id)
{
    emit moveEntered(id);
}
