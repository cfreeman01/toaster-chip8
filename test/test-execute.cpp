#include "emulator/instructionExecutor.h"
#include "CppUTest/TestHarness.h"
#include "stringConversions.h"

TEST_GROUP(ExecuteTests)
{
    EmulatorState state;

    void setup()
    {
        state = EmulatorState();
    }

    void teardown()
    {

    }
};

TEST(ExecuteTests, ClearScreen)
{

}