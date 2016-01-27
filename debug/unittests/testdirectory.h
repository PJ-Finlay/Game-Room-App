#ifndef TESTDIRECTORY_H
#define TESTDIRECTORY_H

/**
 * @brief The TestDirectory class provides links to blocks of unit tests. The primary method of this class is allTests(), which tests all of the currently written unit tests.
 * There are also methods for testing other blocks of unit tests.
 */
class TestDirectory
{
public:
    /**
     * @brief Runs every currently written unit test.
     */
    static void allTests();

    /**
     * @brief Runs all of the unit tests for games
     * @return If all of the tests were passed
     */
    static bool allGames();

    /**
     * @brief Runs all of the AIAlgorithm tests
     * @return If all of the tests were passed
     */
    static bool allAIAlgorithms();

    /**
     * @brief Runs all of the other tests that don't fit well into a category
     * @return If all of the tests were passed
     */
    static bool otherTests();
};

#endif // TESTDIRECTORY_H
