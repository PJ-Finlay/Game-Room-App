#include "uiwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UIWidget *w = new UIWidget();
    w->show();

    return a.exec();
}
