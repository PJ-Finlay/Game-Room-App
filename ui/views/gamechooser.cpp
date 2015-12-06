#include "gamechooser.h"

#include <QPushButton>

GameChooser::GameChooser(QWidget *parent) : View(parent)
{
    QPushButton *b = new QPushButton("Game Chooser",this);
    b->show();
}

