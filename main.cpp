#include <QApplication>

#include "mainview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainView* m = new MainView();
    m->show();

    return a.exec();
}
