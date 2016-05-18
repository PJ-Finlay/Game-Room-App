#include "debugsandbox.h"

#include <QDebug>
#include "debug/unittests/testdirectory.h"
#include "cli.h"
#include <iostream>
#include <string>

#include <QThread>

using namespace std;


void DebugSandbox::test()
{
    qDebug() << "1";
    QThread::sleep(1);
    qDebug() << "2";
    QThread::sleep(2);
    qDebug() << "3";
    QThread::sleep(3);
    qDebug() << "4";
    QThread::sleep(4);

}

void DebugSandbox::cli()
{
    CLI::play();
}

void DebugSandbox::unitests()
{
    TestDirectory::allTests();
}

