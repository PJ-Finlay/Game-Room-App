#include "playerselection.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

#include <QDebug>

PlayerSelection::PlayerSelection(QList<int> validPlayers, QWidget *parent) : QWidget(parent)
{
    numberOfPlayers = validPlayers.at(0);

    QVBoxLayout* layout = new QVBoxLayout(this);

    //Number of Players
    QLabel* numberOfPlayersTitle = new QLabel("Number of Players",this);
    layout->addWidget(numberOfPlayersTitle);
    QWidget* numberOfPlayersWidget = new QWidget(this);
    layout->addWidget(numberOfPlayersWidget);
    QHBoxLayout* numberOfPlayersLayout = new QHBoxLayout(numberOfPlayersWidget);
    numberOfPlayersButtons = QList<PushButtonWithId*>();
    for(int i = 0; i < validPlayers.size(); i++){
        PushButtonWithId* btn = new PushButtonWithId(QString::number(validPlayers.at(i)),QString::number(validPlayers.at(i)),numberOfPlayersWidget);
        btn->setCheckable(true);
        numberOfPlayersButtons.append(btn);
        QObject::connect(btn,SIGNAL(clicked(QString)),this,SLOT(numberOfPlayersSelectionMade(QString)));
        numberOfPlayersLayout->addWidget(btn);
    }

    QLabel* typeOfPlayersTitle = new QLabel("Type of Player",this);
    layout->addWidget(typeOfPlayersTitle);
    typeOfPlayersWidget = new QWidget(this);
    layout->addWidget(typeOfPlayersWidget);
    typeOfPlayersLayout = new QHBoxLayout(typeOfPlayersWidget);
    typeOfPlayersButtons = QList<PushButtonWithId*>();
    for(int i = 0; i < numberOfPlayers; i++){
        addTypeOfPlayerButton();
    }


    numberOfPlayersSelectionMade(QString::number(validPlayers.at(0))); //Set first element as starting checked
    this->setLayout(layout);
}

QString PlayerSelection::getPlayerSelection()
{
    QString toReturn;
    for(int i = 0; i < typeOfPlayersButtons.size(); i++){
        QString toAppend;
        if(typeOfPlayersButtons.at(i)->isChecked()){
            toAppend = "h";
        }else{
            toAppend = "c";
        }
        toReturn.append(toAppend);
    }
    return toReturn;
}

void PlayerSelection::addTypeOfPlayerButton()
{
    int buttonIndex = typeOfPlayersButtons.size();
    PushButtonWithId* btn = new PushButtonWithId(QString::number(buttonIndex),typeOfPlayersWidget);
    btn->setCheckable(true);
    typeOfPlayersButtons.append(btn);
    QObject::connect(btn,SIGNAL(clicked(QString)),this,SLOT(typeOfPlayerChange(QString)));
    typeOfPlayersLayout->addWidget(btn);
    if(buttonIndex == 0) btn->setChecked(true);
    updateTypeOfPlayerButton(buttonIndex);
}

void PlayerSelection::updateTypeOfPlayerButton(int index)
{
    if(typeOfPlayersButtons.at(index)->isChecked()){
        typeOfPlayersButtons.at(index)->setText("Human");
    }else{
        typeOfPlayersButtons.at(index)->setText("Computer");
    }
}

void PlayerSelection::numberOfPlayersSelectionMade(QString selection)
{
    numberOfPlayers = selection.toInt();
    //Uncheck other buttons
    for(int i = 0; i < numberOfPlayersButtons.size(); i++){
        if(numberOfPlayersButtons.at(i)->getId().compare(selection) == 0){
            numberOfPlayersButtons.at(i)->setChecked(true);
        }else{
            numberOfPlayersButtons.at(i)->setChecked(false);
        }
    }

    while(typeOfPlayersButtons.size() < numberOfPlayers){ //If there are too few buttons
        addTypeOfPlayerButton();
    }
    while(typeOfPlayersButtons.size() > numberOfPlayers){ //If there are too many buttons
        PushButtonWithId* buttonToRemove = typeOfPlayersButtons.takeLast();
        typeOfPlayersLayout->removeWidget(buttonToRemove);
        delete buttonToRemove;
    }
}

void PlayerSelection::typeOfPlayerChange(QString selection)
{
    updateTypeOfPlayerButton(selection.toInt());
}
