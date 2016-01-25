#ifndef DEBUGSANDBOX_H
#define DEBUGSANDBOX_H
/**
 * @brief The DebugSandbox class provides a place to test code that is being worked on. By uncommenting a #define in main.cpp you divert the control flow away from the main program and to the test method.
 *
 */
class DebugSandbox
{
public:
    /**
     * @brief Where code being used in the DebugSandbox is put
     */
    static void test();

private:
    /**
     * @brief Runs the CLI
     */
    static void cli();

    /**
     * @brief Runs all of the unit tests
     */
    static void unitests();
};

#endif // DEBUGSANDBOX_H
