#include "gamechooser.h"

#include <QObject>
#include <QVBoxLayout>
#include <QPushButton>

GameChooser::GameChooser(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout();

    QPushButton *b = new QPushButton("Chess",this);
    layout->addWidget(b);
    QObject::connect(b,SIGNAL(clicked()),this,SLOT(selectGame()));

    this->setLayout(layout);

    emit gameChosen();
}
void GameChooser::selectGame(){
    emit gameChosen();
}

