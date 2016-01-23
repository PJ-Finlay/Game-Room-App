#include "debugsandbox.h"

#include <memory>
#include <QString>

#include "debug/unittests/testdirectory.h"
#include "cli.h"

#include "debug/unittests/gametests/checkerstests.h"

void DebugSandbox::test()
{
    //CheckersTests::allTests();
    TestDirectory::allTests();
    //CLI::play();
}

