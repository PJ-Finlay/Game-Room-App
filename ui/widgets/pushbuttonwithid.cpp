#include "pushbuttonwithid.h"

PushButtonWithId::PushButtonWithId(QString id,QWidget* parent) : QPushButton(parent)
{
    this->id = id;
    QObject::connect(this,SIGNAL(clicked(bool)),this,SLOT(clicked()));
}

PushButtonWithId::PushButtonWithId(QString id,QString text, QWidget* parent) : QPushButton(text,parent)
{
    this->id = id;
    QObject::connect(this,SIGNAL(clicked(bool)),this,SLOT(clicked()));
}



QString PushButtonWithId::getId() const
{
    return id;
}

void PushButtonWithId::setId(const QString &value)
{
    id = value;
}

void PushButtonWithId::clicked()
{
    emit clicked(id);
}
