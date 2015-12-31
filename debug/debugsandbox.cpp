#include "debugsandbox.h"

#include "debug/unittests/testdirectory.h"

void DebugSandbox::test()
{
    TestDirectory::allTests();
}
