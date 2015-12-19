#include "gameplay.h"

#include <QPushButton>
#include <QVBoxLayout>

GamePlay::GamePlay(Game game, QWidget* parent) : QWidget(parent)
{
    QPushButton* returnToGameChooserButton = new QPushButton("<-");
    QWidget* gameWidget = game.getGameWidget();
    gameWidget->setParent(this);
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(returnToGameChooserButton);
    layout->addWidget(gameWidget);
    this->setLayout(layout);
    QObject::connect(returnToGameChooserButton,SIGNAL(clicked(bool)),this,SLOT(returnToGameChooser()));

}

void GamePlay::returnToGameChooser(){
    emit returnToGameChooserClicked();
}
