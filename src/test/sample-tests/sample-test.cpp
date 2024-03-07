#include "CppUTest/TestHarness.h"
#include "emulator/emulator.h"

TEST_GROUP(SampleTests)
{
  void setup()
  {
  }

  void teardown() 
  {
  }
};

TEST(SampleTests, PassSample)
{
    CHECK_EQUAL(emu_printhello(), 69);
}