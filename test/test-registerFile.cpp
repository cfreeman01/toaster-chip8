#include "CppUTest/TestHarness.h"
#include "emulator/registerFile.h"
#include "stringConversions.h"

TEST_GROUP(RegisterTests)
{
    RegisterFile  registerFile;
    const uint8_t writeVal = 0xAA;
    uint8_t       readVal;
    const uint8_t initReadVal = 0xFF;
    EmuErrorCode  retVal;

    void setup()
    {
        registerFile = RegisterFile();
        readVal      = initReadVal;
        retVal       = EmuErrorCode::SUCCESS;
    }

    void teardown()
    {

    }
};

TEST(RegisterTests, ReadWriteInRange)
{
    for(uint8_t reg = 0; reg < RegisterFile::NUM_REGS; reg++)
    {
        retVal = registerFile.writeReg(reg, writeVal);
        CHECK_EQUAL(EmuErrorCode::SUCCESS, retVal);

        retVal = registerFile.readReg(reg, &readVal);
        CHECK_EQUAL(EmuErrorCode::SUCCESS, retVal);

        CHECK_EQUAL(writeVal, readVal);
    }
}

TEST(RegisterTests, ReadWriteOutOfRange)
{
    retVal = registerFile.writeReg(RegisterFile::NUM_REGS, writeVal);
    CHECK_EQUAL(EmuErrorCode::REG_RANGE, retVal);

    retVal = registerFile.readReg(RegisterFile::NUM_REGS, &readVal);
    CHECK_EQUAL(EmuErrorCode::REG_RANGE, retVal);
    
    CHECK_EQUAL(initReadVal, readVal);
}