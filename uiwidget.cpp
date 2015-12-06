#include "uiwidget.h"

#include <QPushButton>

#include "ui/views/gamechooser.h"

UIWidget::UIWidget(QWidget *parent) : QWidget(parent)
{
    GameChooser *v = new GameChooser(this);
    v->show();
}
