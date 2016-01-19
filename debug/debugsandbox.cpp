#include "debugsandbox.h"

#include <memory>
#include <QString>

#include "debug/unittests/testdirectory.h"
#include "cli.h"

void DebugSandbox::test()
{
    QString* s = new QString("Testing");
    std::shared_ptr<QString> sp(new QString("Test"));
    //TestDirectory::allTests();
    //CLI::play();
}

