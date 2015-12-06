#include "mainview.h"

#include <QPushButton>
#include <QVBoxLayout>

#include "ui/views/gamechooser.h"

MainView::MainView(QWidget *parent) : QWidget(parent)
{
    //layout is the layout for the MainView
    layout = new QVBoxLayout();
    this->setLayout(layout);

    //Creates the initial layout which is GameChooser
    QVBoxLayout *gameChooserLayout = new QVBoxLayout();
    GameChooser *gameChooser = new GameChooser();
    gameChooserLayout->addWidget(gameChooser);

    //Connects The gameChosen signal in gameChooser to MainView's openGame slot
    QObject::connect(gameChooser, SIGNAL(gameChosen()),this, SLOT(openGame()));

    //Makes gameChooserLayout the layout that is being viewed
    layout->addLayout(gameChooserLayout);
    currentLayout = gameChooserLayout;

    //layout->removeItem(gameChooserLayout);

}

void MainView::openGame(){
    //Create the game layout
    QVBoxLayout *gameLayout = new QVBoxLayout();
    QPushButton *b = new QPushButton("Game");
    gameLayout->addWidget(b);

    //Reset the layout of the MainView to the game layout
    layout->removeItem(currentLayout);
    layout->addLayout(gameLayout);
    delete currentLayout;
    currentLayout = gameLayout;
}
