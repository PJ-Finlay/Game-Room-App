#include <QApplication>

#include "mainview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Create the main view of the application and show it
    MainView* m = new MainView();
    m->show();

    return a.exec();
}
