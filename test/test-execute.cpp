#include "emulator/instructionExecutor.h"
#include "CppUTest/TestHarness.h"
#include "stringConversions.h"
#include "chipRendererMock.h"
#include <iostream>

TEST_GROUP(ExecuteTests)
{
    EmulatorState    state;
    CHIPRendererMock renderer;
    const uint16_t   MEM_LOAD_ADDR = 0xA;
    const uint8_t    VF            = 0xF;

    void setup()
    {
        state = EmulatorState();
        state.renderer = &renderer;
    }

    void teardown()
    {

    }
};

TEST(ExecuteTests, DrawSprite)
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