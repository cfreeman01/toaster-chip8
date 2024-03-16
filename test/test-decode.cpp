#include "CppUTest/TestHarness.h"
#include "emulator/instructionDecoder.h"
#include "emulator/chipInstruction.h"
#include "stringConversions.h"

TEST_GROUP(DecodeTests){
    uint16_t opcode;
    CHIPInstruction ins;
    static const uint8_t ARGS_SIZE = 3;
    uint16_t args[ARGS_SIZE];

    void setup()
    {
        for(int i = 0; i < ARGS_SIZE; i++)
            args[i] = 0;
    }

    void teardown()
    {

    }
};

TEST(DecodeTests, Invalid)
{
    opcode = 0x0000; 
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_INVALID, ins);
}

TEST(DecodeTests, _00E0)
{
    opcode = 0x00E0; 
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_00E0, ins);
}

TEST(DecodeTests, _00EE)
{
    opcode = 0x00EE; 
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_00EE, ins);
}

TEST(DecodeTests, _1NNN)
{
    opcode = 0x1FFF; 
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_1NNN, ins);
    CHECK_EQUAL(0x0FFF, args[0]);
}

TEST(DecodeTests, _2NNN)
{
    opcode = 0x2FFF; 
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_2NNN, ins);
    CHECK_EQUAL(0x0FFF, args[0]);
}

TEST(DecodeTests, _3XNN)
{
    opcode = 0x3EFF;
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_3XNN, ins);
    CHECK_EQUAL(0x000E, args[0]);
    CHECK_EQUAL(0x00FF, args[1]);
}

TEST(DecodeTests, _4XNN)
{
    opcode = 0x4EFF;
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_4XNN, ins);
    CHECK_EQUAL(0x000E, args[0]);
    CHECK_EQUAL(0x00FF, args[1]);
}

TEST(DecodeTests, _5XY0)
{
    opcode = 0x5120;
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_5XY0, ins);
    CHECK_EQUAL(0x0001, args[0]);
    CHECK_EQUAL(0x0002, args[1]);
}

TEST(DecodeTests, _6XNN)
{
    opcode = 0x6EFF;
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_6XNN, ins);
    CHECK_EQUAL(0x000E, args[0]);
    CHECK_EQUAL(0x00FF, args[1]);
}

TEST(DecodeTests, _7XNN)
{
    opcode = 0x7EFF;
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_7XNN, ins);
    CHECK_EQUAL(0x000E, args[0]);
    CHECK_EQUAL(0x00FF, args[1]);
}

TEST(DecodeTests, _8XY0)
{
    opcode = 0x8120;
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_8XY0, ins);
    CHECK_EQUAL(0x0001, args[0]);
    CHECK_EQUAL(0x0002, args[1]);
}

TEST(DecodeTests, _8XY1)
{
    opcode = 0x8121;
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_8XY1, ins);
    CHECK_EQUAL(0x0001, args[0]);
    CHECK_EQUAL(0x0002, args[1]);
}

TEST(DecodeTests, _8XY2)
{
    opcode = 0x8122;
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_8XY2, ins);
    CHECK_EQUAL(0x0001, args[0]);
    CHECK_EQUAL(0x0002, args[1]);
}

TEST(DecodeTests, _8XY3)
{
    opcode = 0x8123;
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_8XY3, ins);
    CHECK_EQUAL(0x0001, args[0]);
    CHECK_EQUAL(0x0002, args[1]);
}

TEST(DecodeTests, _8XY4)
{
    opcode = 0x8124;
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_8XY4, ins);
    CHECK_EQUAL(0x0001, args[0]);
    CHECK_EQUAL(0x0002, args[1]);
}

TEST(DecodeTests, _8XY5)
{
    opcode = 0x8125;
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_8XY5, ins);
    CHECK_EQUAL(0x0001, args[0]);
    CHECK_EQUAL(0x0002, args[1]);
}

TEST(DecodeTests, _8XY6)
{
    opcode = 0x8126;
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_8XY6, ins);
    CHECK_EQUAL(0x0001, args[0]);
    CHECK_EQUAL(0x0002, args[1]);
}

TEST(DecodeTests, _8XY7)
{
    opcode = 0x8127;
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_8XY7, ins);
    CHECK_EQUAL(0x0001, args[0]);
    CHECK_EQUAL(0x0002, args[1]);
}

TEST(DecodeTests, _8XYE)
{
    opcode = 0x812E;
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_8XYE, ins);
    CHECK_EQUAL(0x0001, args[0]);
    CHECK_EQUAL(0x0002, args[1]);
}

TEST(DecodeTests, _9XY0)
{
    opcode = 0x9120;
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_9XY0, ins);
    CHECK_EQUAL(0x0001, args[0]);
    CHECK_EQUAL(0x0002, args[1]);
}

TEST(DecodeTests, _ANNN)
{
    opcode = 0xAFFF; 
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_ANNN, ins);
    CHECK_EQUAL(0x0FFF, args[0]);
}

TEST(DecodeTests, _BNNN)
{
    opcode = 0xBFFF; 
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_BNNN, ins);
    CHECK_EQUAL(0x0FFF, args[0]);
}

TEST(DecodeTests, _CXNN)
{
    opcode = 0xC1FF; 
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_CXNN, ins);
    CHECK_EQUAL(0x0001, args[0]);
    CHECK_EQUAL(0x00FF, args[1]);
}

TEST(DecodeTests, _DXYN)
{
    opcode = 0xD123; 
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_DXYN, ins);
    CHECK_EQUAL(0x0001, args[0]);
    CHECK_EQUAL(0x0002, args[1]);
    CHECK_EQUAL(0x0003, args[2]);
}

TEST(DecodeTests, _EX9E)
{
    opcode = 0xE19E; 
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_EX9E, ins);
    CHECK_EQUAL(0x0001, args[0]);
}

TEST(DecodeTests, _EXA1)
{
    opcode = 0xE1A1; 
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_EXA1, ins);
    CHECK_EQUAL(0x0001, args[0]);
}

TEST(DecodeTests, _FX07)
{
    opcode = 0xF107; 
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_FX07, ins);
    CHECK_EQUAL(0x0001, args[0]);
}

TEST(DecodeTests, _FX0A)
{
    opcode = 0xF10A; 
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_FX0A, ins);
    CHECK_EQUAL(0x0001, args[0]);
}

TEST(DecodeTests, _FX15)
{
    opcode = 0xF115; 
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_FX15, ins);
    CHECK_EQUAL(0x0001, args[0]);
}

TEST(DecodeTests, _FX18)
{
    opcode = 0xF118; 
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_FX18, ins);
    CHECK_EQUAL(0x0001, args[0]);
}

TEST(DecodeTests, _FX1E)
{
    opcode = 0xF11E; 
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_FX1E, ins);
    CHECK_EQUAL(0x0001, args[0]);
}

TEST(DecodeTests, _FX29)
{
    opcode = 0xF129; 
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_FX29, ins);
    CHECK_EQUAL(0x0001, args[0]);
}

TEST(DecodeTests, _FX33)
{
    opcode = 0xF133; 
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_FX33, ins);
    CHECK_EQUAL(0x0001, args[0]);
}

TEST(DecodeTests, _FX55)
{
    opcode = 0xF155; 
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_FX55, ins);
    CHECK_EQUAL(0x0001, args[0]);
}

TEST(DecodeTests, _FX65)
{
    opcode = 0xF165; 
    ins = InstructionDecoder::decode(opcode, args);

    CHECK_EQUAL(CHIPInstruction::_FX65, ins);
    CHECK_EQUAL(0x0001, args[0]);
}