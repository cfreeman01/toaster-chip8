#include "CppUTest/TestHarness.h"
#include "emulator/memory.h"
#include "stringConversions.h"

TEST_GROUP(MemoryTests){

    Memory memory;
    static const uint8_t LEN = 10;
    uint8_t writeVals[LEN]   = {0xAA, 0xFF, 0x00, 0xBE, 0xEF, 0xDE, 0xAD, 0xFF, 0x12, 0x34};
    uint8_t readVals[LEN]    = {0};
    EmuErrorCode retVal;

    void setup()
    {
        memory = Memory();
        retVal = EmuErrorCode::SUCCESS;
        for(int i = 0; i < LEN; i++)
            readVals[i] = 0;
    }

    void teardown()
    {

    }
};

TEST(MemoryTests, ReadWriteInRange)
{
    uint16_t addr = 0x00;
    while(addr + LEN <= Memory::MEM_SIZE)
    {
        retVal = memory.write(addr, writeVals, LEN);
        CHECK_EQUAL(EmuErrorCode::SUCCESS, retVal);

        retVal = memory.read(addr, readVals, LEN);
        CHECK_EQUAL(EmuErrorCode::SUCCESS, retVal);

        for(int i = 0; i < LEN; i++)
            CHECK_EQUAL(writeVals[i], readVals[i]);

        addr += LEN;
    }
}

TEST(MemoryTests, ReadWriteOutOfRange)
{
    uint16_t addr = Memory::MEM_SIZE;

    retVal = memory.write(addr, writeVals, 1);
    CHECK_EQUAL(EmuErrorCode::MEM_RANGE, retVal);

    retVal = memory.read(addr, readVals, 1);
    CHECK_EQUAL(EmuErrorCode::MEM_RANGE, retVal);

    for (int i = 0; i < LEN; i++)
        CHECK_EQUAL(0, readVals[i]);
}