#include "mainview.h"

#include <QPushButton>
#include <QVBoxLayout>

#include "ui/views/gamechooser.h"
#include "ui/views/gameplay.h"

MainView::MainView(QWidget *parent) : QWidget(parent)
{
    //layout is the layout for the MainView
    layout = new QVBoxLayout();

    //Creates the initial view which is GameChooser
    GameChooser* gameChooser = new GameChooser(this);

    //Connects The gameChosen signal in gameChooser to MainView's openGame slot
    QObject::connect(gameChooser, SIGNAL(gameChosen(Game)),this, SLOT(openGame(Game)));

    //Makes gameChooser the widget that is being viewed
    layout->addWidget(gameChooser);
    currentWidget = gameChooser;

    //Set layout as the layout for the MainView (This is at the end of the constructor so that the layout is completely constructed before it is displayed
    this->setLayout(layout);
}

void MainView::openGame(Game game){
    //Create the game layout
    GamePlay* gameplay = new GamePlay(game,this);

    //Reset the layout of the MainView to the game layout
    layout->removeWidget(currentWidget);
    layout->addWidget(gameplay);
    delete currentWidget;
    currentWidget = gameplay;
}
