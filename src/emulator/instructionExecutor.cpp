#include <iostream>
#include "emulator/instructionExecutor.h"
#include "emulator/instructionDecoder.h"
using namespace std;

map<CHIPInstruction, InstructionExecutor::InsPtr> InstructionExecutor::instructionMap = 
{
    {CHIPInstruction::_00E0, &InstructionExecutor::ex_00E0},
    {CHIPInstruction::_00EE, &InstructionExecutor::ex_00EE},
    {CHIPInstruction::_1NNN, &InstructionExecutor::ex_1NNN},
    {CHIPInstruction::_2NNN, &InstructionExecutor::ex_2NNN},
    {CHIPInstruction::_3XNN, &InstructionExecutor::ex_3XNN},
    {CHIPInstruction::_4XNN, &InstructionExecutor::ex_4XNN},
    {CHIPInstruction::_5XY0, &InstructionExecutor::ex_5XY0},
    {CHIPInstruction::_6XNN, &InstructionExecutor::ex_6XNN},
    {CHIPInstruction::_7XNN, &InstructionExecutor::ex_7XNN},
    {CHIPInstruction::_8XY0, &InstructionExecutor::ex_8XY0},
    {CHIPInstruction::_8XY1, &InstructionExecutor::ex_8XY1},
    {CHIPInstruction::_8XY2, &InstructionExecutor::ex_8XY2},
    {CHIPInstruction::_8XY3, &InstructionExecutor::ex_8XY3},
    {CHIPInstruction::_8XY4, &InstructionExecutor::ex_8XY4},
    {CHIPInstruction::_8XY5, &InstructionExecutor::ex_8XY5},
    {CHIPInstruction::_8XY6, &InstructionExecutor::ex_8XY6},
    {CHIPInstruction::_8XY7, &InstructionExecutor::ex_8XY7},
    {CHIPInstruction::_8XYE, &InstructionExecutor::ex_8XYE},
    {CHIPInstruction::_9XY0, &InstructionExecutor::ex_9XY0},
    {CHIPInstruction::_ANNN, &InstructionExecutor::ex_ANNN},
    {CHIPInstruction::_BNNN, &InstructionExecutor::ex_BNNN},
    {CHIPInstruction::_CXNN, &InstructionExecutor::ex_CXNN},
    {CHIPInstruction::_DXYN, &InstructionExecutor::ex_DXYN},
    {CHIPInstruction::_EX9E, &InstructionExecutor::ex_EX9E},
    {CHIPInstruction::_EXA1, &InstructionExecutor::ex_EXA1},
    {CHIPInstruction::_FX07, &InstructionExecutor::ex_FX07},
    {CHIPInstruction::_FX0A, &InstructionExecutor::ex_FX0A},
    {CHIPInstruction::_FX15, &InstructionExecutor::ex_FX15},
    {CHIPInstruction::_FX18, &InstructionExecutor::ex_FX18},
    {CHIPInstruction::_FX1E, &InstructionExecutor::ex_FX1E},
    {CHIPInstruction::_FX29, &InstructionExecutor::ex_FX29},
    {CHIPInstruction::_FX33, &InstructionExecutor::ex_FX33},
    {CHIPInstruction::_FX55, &InstructionExecutor::ex_FX55},
    {CHIPInstruction::_FX65, &InstructionExecutor::ex_FX65}
};

void InstructionExecutor::executeInstruction(uint16_t opcode, EmulatorState & emuState)
{
    state = &emuState;

    CHIPInstruction ins = InstructionDecoder::decode(opcode, args);

    (*instructionMap[ins])();
}

void InstructionExecutor::ex_00E0()
{
    state->display.clear();
}

void InstructionExecutor::ex_00EE()
{
    // Implementation for opcode 00EE
}

void InstructionExecutor::ex_1NNN()
{
    // Implementation for opcode 1NNN
}

void InstructionExecutor::ex_2NNN()
{
    // Implementation for opcode 2NNN
}

void InstructionExecutor::ex_3XNN()
{
    // Implementation for opcode 3XNN
}

void InstructionExecutor::ex_4XNN()
{
    // Implementation for opcode 4XNN
}

void InstructionExecutor::ex_5XY0()
{
    // Implementation for opcode 5XY0
}

void InstructionExecutor::ex_6XNN()
{
    // Implementation for opcode 6XNN
}

void InstructionExecutor::ex_7XNN()
{
    // Implementation for opcode 7XNN
}

void InstructionExecutor::ex_8XY0()
{
    // Implementation for opcode 8XY0
}

void InstructionExecutor::ex_8XY1()
{
    // Implementation for opcode 8XY1
}

void InstructionExecutor::ex_8XY2()
{
    // Implementation for opcode 8XY2
}

void InstructionExecutor::ex_8XY3()
{
    // Implementation for opcode 8XY3
}

void InstructionExecutor::ex_8XY4()
{
    // Implementation for opcode 8XY4
}

void InstructionExecutor::ex_8XY5()
{
    // Implementation for opcode 8XY5
}

void InstructionExecutor::ex_8XY6()
{
    // Implementation for opcode 8XY6
}

void InstructionExecutor::ex_8XY7()
{
    // Implementation for opcode 8XY7
}

void InstructionExecutor::ex_8XYE()
{
    // Implementation for opcode 8XYE
}

void InstructionExecutor::ex_9XY0()
{
    // Implementation for opcode 9XY0
}

void InstructionExecutor::ex_ANNN()
{
    // Implementation for opcode ANNN
}

void InstructionExecutor::ex_BNNN()
{
    // Implementation for opcode BNNN
}

void InstructionExecutor::ex_CXNN()
{
    // Implementation for opcode CXNN
}

void InstructionExecutor::ex_DXYN()
{
    uint8_t x, y, n = args[2];
    uint8_t* sprite;

    state->registerFile.readReg(args[0], &x);
    state->registerFile.readReg(args[1], &y);

    state->memory.read(state->indexReg, sprite, n);

    if(state->display.drawSprite(x, y, sprite, n))
        state->registerFile.writeReg(0xF, 1);
    else
        state->registerFile.writeReg(0xF, 0);
}

void InstructionExecutor::ex_EX9E()
{
    // Implementation for opcode EX9E
}

void InstructionExecutor::ex_EXA1()
{
    // Implementation for opcode EXA1
}

void InstructionExecutor::ex_FX07()
{
    // Implementation for opcode FX07
}

void InstructionExecutor::ex_FX0A()
{
    // Implementation for opcode FX0A
}

void InstructionExecutor::ex_FX15()
{
    // Implementation for opcode FX15
}

void InstructionExecutor::ex_FX18()
{
    // Implementation for opcode FX18
}

void InstructionExecutor::ex_FX1E()
{
    // Implementation for opcode FX1E
}

void InstructionExecutor::ex_FX29()
{
    // Implementation for opcode FX29
}

void InstructionExecutor::ex_FX33()
{
    // Implementation for opcode FX33
}

void InstructionExecutor::ex_FX55()
{
    // Implementation for opcode FX55
}

void InstructionExecutor::ex_FX65()
{
    // Implementation for opcode FX65
}