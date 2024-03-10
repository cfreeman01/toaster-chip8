#include "CppUTest/TestHarness.h"
#include "emulator/registerFile.h"

TEST_GROUP(RegisterTests){

    RegisterFile registerFile;

    void setup()
    {
        registerFile = RegisterFile();
    }

    void teardown()
    {

    }
};

TEST(RegisterTests, ReadWrite)
{
    const uint8_t writeVal = 0xAA;
    for(uint8_t regNum = 0; regNum < NUM_REGS; regNum++)
    {
        Register reg = static_cast<Register>(regNum);
        registerFile.writeReg(reg, writeVal);
        CHECK_EQUAL(registerFile.readReg(reg), writeVal);
    }
}