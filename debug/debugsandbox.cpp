#include "debugsandbox.h"

#include <memory>
#include <QString>

#include "debug/unittests/testdirectory.h"
#include "cli.h"

#include "debug/unittests/gametests/checkerstests.h"

void DebugSandbox::test()
{
    unitests();
}

void DebugSandbox::cli()
{
    CLI::play();
}

void DebugSandbox::unitests()
{
    TestDirectory::allTests();
}

