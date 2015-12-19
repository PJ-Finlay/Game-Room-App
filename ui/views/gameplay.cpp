#include "gameplay.h"

#include <QLabel>
#include <QVBoxLayout>

GamePlay::GamePlay(Game game, QWidget* parent) : QWidget(parent)
{
    QLabel* q = new QLabel(game.getName(),this);
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(q);
    this->setLayout(layout);
}

