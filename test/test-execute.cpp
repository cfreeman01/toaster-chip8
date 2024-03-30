#include "emulator/instructionExecutor.h"
#include "CppUTest/TestHarness.h"
#include "stringConversions.h"
#include <iostream>

TEST_GROUP(ExecuteTests)
{
    EmulatorState    state;
    const uint16_t   MEM_LOAD_ADDR = 0xA;
    const uint8_t    VF            = 0xF;

    void setup()
    {
        state = EmulatorState();
        state.registerFile.writeReg(VF, 0xFF);
    }

    void teardown()
    {

    }
};

TEST(ExecuteTests, _6XNN)
{
    const uint8_t  VX     = 1;
    const uint8_t  VAL    = 0xFF;
    const uint16_t OPCODE = 0x6000 | (VX <<  8) | VAL;
    uint8_t readVal;

    InstructionExecutor::execute(OPCODE, state);

    state.registerFile.readReg(VX, &readVal);

    CHECK_EQUAL(VAL, readVal);
}

TEST(ExecuteTests, _7XNN_normal)
{
    const uint8_t  VX      = 1;
    const uint8_t  VAL     = 5;
    const uint8_t  ADD_VAL = 10;
    const uint16_t OPCODE  = 0x7000 | (VX <<  8) | ADD_VAL;
    uint8_t readVal;

    state.registerFile.writeReg(VX, VAL);

    InstructionExecutor::execute(OPCODE, state);

    state.registerFile.readReg(VX, &readVal);

    CHECK_EQUAL(VAL + ADD_VAL, readVal);
}

TEST(ExecuteTests, _7XNN_overflow)
{
    const uint8_t  VX      = 1;
    const uint8_t  VAL     = 250;
    const uint8_t  ADD_VAL = 10;
    const uint8_t  EXPECT  = 4;
    const uint16_t OPCODE  = 0x7000 | (VX <<  8) | ADD_VAL;
    uint8_t readVal;

    state.registerFile.writeReg(VX, VAL);

    InstructionExecutor::execute(OPCODE, state);

    state.registerFile.readReg(VX, &readVal);

    CHECK_EQUAL(EXPECT, readVal);
}

TEST(ExecuteTests, _8XY0)
{
    const uint8_t  VX     = 1;
    const uint8_t  VY     = 2;
    const uint8_t  VAL    = 0xFF;
    const uint16_t OPCODE = 0x8000 | (VX <<  8) | (VY << 4);
    uint8_t readVal;

    state.registerFile.writeReg(VY, VAL);

    InstructionExecutor::execute(OPCODE, state);

    state.registerFile.readReg(VX, &readVal);

    CHECK_EQUAL(VAL, readVal);
}

TEST(ExecuteTests, _8XY1)
{
    const uint8_t  VX      = 1;
    const uint8_t  VY      = 2;
    const uint8_t  VX_VAL  = 0xBE;
    const uint8_t  VY_VAL  = 0xEF; 
    const uint16_t OPCODE  = 0x8001 | (VX <<  8) | (VY << 4);
    uint8_t readVal;

    state.registerFile.writeReg(VX, VX_VAL);
    state.registerFile.writeReg(VY, VY_VAL);

    InstructionExecutor::execute(OPCODE, state);

    state.registerFile.readReg(VX, &readVal);

    CHECK_EQUAL(VX_VAL | VY_VAL, readVal);
}

TEST(ExecuteTests, _8XY2)
{
    const uint8_t  VX      = 1;
    const uint8_t  VY      = 2;
    const uint8_t  VX_VAL  = 0xBE;
    const uint8_t  VY_VAL  = 0xEF; 
    const uint16_t OPCODE  = 0x8002 | (VX <<  8) | (VY << 4);
    uint8_t readVal;

    state.registerFile.writeReg(VX, VX_VAL);
    state.registerFile.writeReg(VY, VY_VAL);

    InstructionExecutor::execute(OPCODE, state);

    state.registerFile.readReg(VX, &readVal);

    CHECK_EQUAL(VX_VAL & VY_VAL, readVal);
}

TEST(ExecuteTests, _8XY3)
{
    const uint8_t  VX      = 1;
    const uint8_t  VY      = 2;
    const uint8_t  VX_VAL  = 0xBE;
    const uint8_t  VY_VAL  = 0xEF; 
    const uint16_t OPCODE  = 0x8003 | (VX <<  8) | (VY << 4);
    uint8_t readVal;

    state.registerFile.writeReg(VX, VX_VAL);
    state.registerFile.writeReg(VY, VY_VAL);

    InstructionExecutor::execute(OPCODE, state);

    state.registerFile.readReg(VX, &readVal);

    CHECK_EQUAL(VX_VAL ^ VY_VAL, readVal);
}

TEST(ExecuteTests, _8XY4_normal)
{
    const uint8_t  VX      = 1;
    const uint8_t  VY      = 2;
    const uint8_t  VX_VAL  = 5;
    const uint8_t  VY_VAL  = 10; 
    const uint16_t OPCODE  = 0x8004 | (VX <<  8) | (VY << 4);
    uint8_t readVal;

    state.registerFile.writeReg(VX, VX_VAL);
    state.registerFile.writeReg(VY, VY_VAL);

    InstructionExecutor::execute(OPCODE, state);

    state.registerFile.readReg(VX, &readVal);

    CHECK_EQUAL(VX_VAL + VY_VAL, readVal);

    state.registerFile.readReg(VF, &readVal);

    CHECK_EQUAL(0, readVal);
}

TEST(ExecuteTests, _8XY4_overflow)
{
    const uint8_t  VX      = 1;
    const uint8_t  VY      = 2;
    const uint8_t  VX_VAL  = 250;
    const uint8_t  VY_VAL  = 10; 
    const uint8_t  EXPECT  = 4;
    const uint16_t OPCODE  = 0x8004 | (VX <<  8) | (VY << 4);
    uint8_t readVal;

    state.registerFile.writeReg(VX, VX_VAL);
    state.registerFile.writeReg(VY, VY_VAL);

    InstructionExecutor::execute(OPCODE, state);

    state.registerFile.readReg(VX, &readVal);

    CHECK_EQUAL(EXPECT, readVal);

    state.registerFile.readReg(VF, &readVal);

    CHECK_EQUAL(1, readVal);
}

TEST(ExecuteTests, _8XY5_normal)
{
    const uint8_t  VX      = 1;
    const uint8_t  VY      = 2;
    const uint8_t  VX_VAL  = 10;
    const uint8_t  VY_VAL  = 5; 
    const uint16_t OPCODE  = 0x8005 | (VX <<  8) | (VY << 4);
    uint8_t readVal;

    state.registerFile.writeReg(VX, VX_VAL);
    state.registerFile.writeReg(VY, VY_VAL);

    InstructionExecutor::execute(OPCODE, state);

    state.registerFile.readReg(VX, &readVal);

    CHECK_EQUAL(VX_VAL - VY_VAL, readVal);

    state.registerFile.readReg(VF, &readVal);

    CHECK_EQUAL(1, readVal);
}

TEST(ExecuteTests, _8XY5_overflow)
{
    const uint8_t  VX      = 1;
    const uint8_t  VY      = 2;
    const uint8_t  VX_VAL  = 5;
    const uint8_t  VY_VAL  = 10; 
    const uint8_t  EXPECT  = 251;
    const uint16_t OPCODE  = 0x8005 | (VX <<  8) | (VY << 4);
    uint8_t readVal;

    state.registerFile.writeReg(VX, VX_VAL);
    state.registerFile.writeReg(VY, VY_VAL);

    InstructionExecutor::execute(OPCODE, state);

    state.registerFile.readReg(VX, &readVal);

    CHECK_EQUAL(EXPECT, readVal);

    state.registerFile.readReg(VF, &readVal);

    CHECK_EQUAL(0, readVal);
}

TEST(ExecuteTests, _8XY6)
{
    const uint8_t  VX      = 1;
    const uint8_t  VY      = 2;
    const uint8_t  VY_VAL  = 0xFF; 
    const uint16_t OPCODE  = 0x8006 | (VX <<  8) | (VY << 4);
    uint8_t readVal;

    state.registerFile.writeReg(VY, VY_VAL);

    InstructionExecutor::execute(OPCODE, state);

    state.registerFile.readReg(VX, &readVal);

    CHECK_EQUAL(VY_VAL >> 1, readVal);

    state.registerFile.readReg(VF, &readVal);

    CHECK_EQUAL(1, readVal);
}

TEST(ExecuteTests, _8XY7_normal)
{
    const uint8_t  VX      = 1;
    const uint8_t  VY      = 2;
    const uint8_t  VX_VAL  = 5;
    const uint8_t  VY_VAL  = 10; 
    const uint16_t OPCODE  = 0x8007 | (VX <<  8) | (VY << 4);
    uint8_t readVal;

    state.registerFile.writeReg(VX, VX_VAL);
    state.registerFile.writeReg(VY, VY_VAL);

    InstructionExecutor::execute(OPCODE, state);

    state.registerFile.readReg(VX, &readVal);

    CHECK_EQUAL(VY_VAL - VX_VAL, readVal);

    state.registerFile.readReg(VF, &readVal);

    CHECK_EQUAL(1, readVal);
}

TEST(ExecuteTests, _8XY7_overflow)
{
    const uint8_t  VX      = 1;
    const uint8_t  VY      = 2;
    const uint8_t  VX_VAL  = 10;
    const uint8_t  VY_VAL  = 5; 
    const uint8_t  EXPECT  = 251;
    const uint16_t OPCODE  = 0x8007 | (VX <<  8) | (VY << 4);
    uint8_t readVal;

    state.registerFile.writeReg(VX, VX_VAL);
    state.registerFile.writeReg(VY, VY_VAL);

    InstructionExecutor::execute(OPCODE, state);

    state.registerFile.readReg(VX, &readVal);

    CHECK_EQUAL(EXPECT, readVal);

    state.registerFile.readReg(VF, &readVal);

    CHECK_EQUAL(0, readVal);
}

TEST(ExecuteTests, _8XYE)
{
    const uint8_t  VX      = 1;
    const uint8_t  VY      = 2;
    const uint8_t  VY_VAL  = 0xFF; 
    const uint8_t  EXPECT  = 0xFE;
    const uint16_t OPCODE  = 0x800E | (VX <<  8) | (VY << 4);
    uint8_t readVal;

    state.registerFile.writeReg(VY, VY_VAL);

    InstructionExecutor::execute(OPCODE, state);

    state.registerFile.readReg(VX, &readVal);

    CHECK_EQUAL(EXPECT, readVal);

    state.registerFile.readReg(VF, &readVal);

    CHECK_EQUAL(1, readVal);
}

TEST(ExecuteTests, _DXYN)
{
    const uint8_t SPRITE_X        = 24;
    const uint8_t SPRITE_Y        = 8;
    const uint8_t VX              = 0;
    const uint8_t VY              = 1;
    const uint32_t N              = 8;
    const uint16_t OPCODE         = 0xD000 | (VX << 8) | (VY << 4) | N;
    uint8_t sprite[N] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    uint64_t expectedDisplay[Display::HEIGHT] = 
    {
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'FF'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'FF'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'FF'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'FF'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        //rest zero
    };
    const uint32_t DISPLAY_SIZE_BYTES = 8 * Display::HEIGHT;

    state.registerFile.writeReg(VX, SPRITE_X);
    state.registerFile.writeReg(VY, SPRITE_Y);
    
    state.memory.write(MEM_LOAD_ADDR, sprite, N);

    state.indexReg = MEM_LOAD_ADDR;

    InstructionExecutor::execute(OPCODE, state);

    for(int i = 0; i < N; i++)
        if(i % 2 == 0)
            sprite[i] = 0x00;

    state.memory.write(MEM_LOAD_ADDR, sprite, N);

    InstructionExecutor::execute(OPCODE, state);

    MEMCMP_EQUAL(expectedDisplay, state.display.getDisplayData(), DISPLAY_SIZE_BYTES);
    
    uint8_t vf;
    state.registerFile.readReg(VF, &vf);
    CHECK_EQUAL(1, vf);
}