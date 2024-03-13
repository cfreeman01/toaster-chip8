#include "CppUTest/CommandLineTestRunner.h"

IMPORT_TEST_GROUP(RegisterTests);
IMPORT_TEST_GROUP(MemoryTests);
IMPORT_TEST_GROUP(DisplayTests);

int main(int argc, char** argv)
{
    return RUN_ALL_TESTS(argc, argv);
}