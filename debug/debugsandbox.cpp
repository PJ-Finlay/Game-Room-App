#include "debugsandbox.h"

#include "debug/unittests/testdirectory.h"
#include "cli.h"

void DebugSandbox::test()
{
    TestDirectory::allTests();
    //CLI::play();
}

