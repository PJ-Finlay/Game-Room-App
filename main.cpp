#include <QApplication>

//#include "mainview.h"


/*Preprocesser Defines:
 *  SANDBOXBUILD - Defined if it is a sandbox build, which directs control flow to  DebugSandbox
 *
 */
#define SANDBOXBUILD



#ifdef SANDBOXBUILD
#include "debug/debugsandbox.h"
#endif

//Removed to supress compiler error
//int main(int argc, char *argv[])
int main()
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
