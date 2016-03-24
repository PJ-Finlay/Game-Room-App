#include <QApplication>
#include <QFile>

#include "ui/mainview.h"
#include "ui/widgets/game_widgets/tictactoegamewidget.h"



/*Preprocesser Defines:
 *  SANDBOXBUILD - Defined if it is a sandbox build, which directs control flow to  DebugSandbox
 *
 */
//#define SANDBOXBUILD



#ifdef SANDBOXBUILD
#include "debug/debugsandbox.h"
#endif

//Removed to supress compiler error
int main(int argc, char *argv[])
{
#ifdef SANDBOXBUILD // Runs the test method of the DebugSandbox if SANDBOXBUILD is enabled
    DebugSandbox::test();
#else //Normal Build
    QApplication a(argc, argv);

    //Set the stylesheet
    QFile file(":/stylesheet.qss");
    file.open(QFile::ReadOnly);
    a.setStyleSheet(QLatin1String(file.readAll()));

    //Create the main view of the application and show it
    MainView* m = new MainView();
    m->show();

    return a.exec();
#endif
}
