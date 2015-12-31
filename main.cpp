#include <QApplication>

#include "mainview.h"


/*Preprocesser Defines:
 *  QT_DEBUG - Defined only in Debugging Builds
 *  SANDBOXBUILD - Defined if it is a sandbox build, which directs control flow to  DebugSandbox
 *
 */
#define SANDBOXBUILD



#ifdef SANDBOXBUILD
#include "debug/debugsandbox.h"
#define QT_DEBUG
#endif

int main(int argc, char *argv[])
{
#ifdef SANDBOXBUILD // Runs the test method of the DebugSandbox if SANDBOXBUILD is enabled
    DebugSandbox::test();
#else //Normal Build
    QApplication a(argc, argv);

    //Create the main view of the application and show it
    MainView* m = new MainView();
    m->show();

    return a.exec();
#endif
}
