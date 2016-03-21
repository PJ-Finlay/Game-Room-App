#include "view.h"

#include <QLayout>

View::View(QWidget *parent) : QWidget(parent)
{
    setIsNormalView(false);
}

bool View::getIsNormalView() const
{
    return isNormalView;
}

void View::setIsNormalView(bool value)
{
    isNormalView = value;
    if(isNormalView){
        this->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::Fixed);
        this->parentWidget()->layout()->setAlignment(Qt::AlignTop);
    }else{
        this->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
        this->parentWidget()->layout()->setAlignment(Qt::AlignVCenter);
    }
}

