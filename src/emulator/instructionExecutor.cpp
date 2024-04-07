#include <iostream>
#include "emulator/instructionExecutor.h"
#include "emulator/instructionDecoder.h"
#include "emulator/emulator.h"
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

uint16_t InstructionExecutor::args[3];

EmulatorState* InstructionExecutor::state;

void InstructionExecutor::execute(uint16_t opcode, EmulatorState & emuState)
{
    state = &emuState;

    CHIPInstruction ins = InstructionDecoder::decode(opcode, args);

    state->programCounter += 2;

    if(ins == CHIPInstruction::_INVALID)
    {
        cout << "Invalid instruction: " << hex << opcode << endl;
        exit(1);
    }

    (*instructionMap[ins])();
}

void InstructionExecutor::ex_00E0()
{
    state->display.clear();
}

void InstructionExecutor::ex_00EE()
{
    uint16_t newPC = state->sysStack.top();
    state->sysStack.pop();

    state->programCounter = newPC;
}

void InstructionExecutor::ex_1NNN()
{
    state->programCounter = args[0];
}

void InstructionExecutor::ex_2NNN()
{
    state->sysStack.push(state->programCounter);

    state->programCounter = args[0];
}

void InstructionExecutor::ex_3XNN()
{
    uint8_t vxVal;

    state->registerFile.readReg(args[0], &vxVal);

    if(vxVal == args[1])
        state->programCounter += 2;
}

void InstructionExecutor::ex_4XNN()
{
    uint8_t vxVal;

    state->registerFile.readReg(args[0], &vxVal);

    if(vxVal != args[1])
        state->programCounter += 2;
}

void InstructionExecutor::ex_5XY0()
{
    uint8_t vxVal, vyVal;

    state->registerFile.readReg(args[0], &vxVal);
    state->registerFile.readReg(args[1], &vyVal);

    if(vxVal == vyVal)
        state->programCounter += 2;
}

void InstructionExecutor::ex_6XNN()
{
    state->registerFile.writeReg(args[0], args[1]);
}

void InstructionExecutor::ex_7XNN()
{
    uint8_t val;
    state->registerFile.readReg(args[0], &val);
    val += args[1];
    state->registerFile.writeReg(args[0], val);
}

void InstructionExecutor::ex_8XY0()
{
    uint8_t val;
    state->registerFile.readReg(args[1], &val);
    state->registerFile.writeReg(args[0], val);
}

void InstructionExecutor::ex_8XY1()
{
    uint8_t xval, yval, res;

    state->registerFile.readReg(args[0], &xval);
    state->registerFile.readReg(args[1], &yval);

    res = xval | yval;

    state->registerFile.writeReg(args[0], res);
}

void InstructionExecutor::ex_8XY2()
{
    uint8_t xval, yval, res;

    state->registerFile.readReg(args[0], &xval);
    state->registerFile.readReg(args[1], &yval);

    res = xval & yval;

    state->registerFile.writeReg(args[0], res);
}

void InstructionExecutor::ex_8XY3()
{
    uint8_t xval, yval, res;

    state->registerFile.readReg(args[0], &xval);
    state->registerFile.readReg(args[1], &yval);

    res = xval ^ yval;

    state->registerFile.writeReg(args[0], res);
}

void InstructionExecutor::ex_8XY4()
{
    uint8_t xval, yval, sum;
    bool carry;

    state->registerFile.readReg(args[0], &xval);
    state->registerFile.readReg(args[1], &yval);

    sum = xval + yval;
    carry = (uint32_t)(xval + yval) > sum;

    state->registerFile.writeReg(args[0], sum);

    if(carry)
        state->registerFile.writeReg(0xF, 0x1);
    else
        state->registerFile.writeReg(0xF, 0x0);
}

void InstructionExecutor::ex_8XY5()
{
    uint8_t xval, yval, diff;
    bool borrow;

    state->registerFile.readReg(args[0], &xval);
    state->registerFile.readReg(args[1], &yval);

    diff   = xval - yval;
    borrow = yval > xval;

    state->registerFile.writeReg(args[0], diff);

    if(borrow)
        state->registerFile.writeReg(0xF, 0x0);
    else
        state->registerFile.writeReg(0xF, 0x1);
}

void InstructionExecutor::ex_8XY6()
{
    uint8_t yval, res, lsb;

    state->registerFile.readReg(args[1], &yval);

    lsb = yval & 0x1;

    res = yval >> 1;

    state->registerFile.writeReg(args[0], res);

    state->registerFile.writeReg(0xF, lsb);
}

void InstructionExecutor::ex_8XY7()
{
    uint8_t xval, yval, diff;
    bool borrow;

    state->registerFile.readReg(args[0], &xval);
    state->registerFile.readReg(args[1], &yval);

    diff   = yval - xval;
    borrow = xval > yval;

    state->registerFile.writeReg(args[0], diff);

    if(borrow)
        state->registerFile.writeReg(0xF, 0x0);
    else
        state->registerFile.writeReg(0xF, 0x1);
}

void InstructionExecutor::ex_8XYE()
{
    uint8_t yval, res, msb;

    state->registerFile.readReg(args[1], &yval);

    msb = (yval & 0x80) >> 7;

    res = yval << 1;

    state->registerFile.writeReg(args[0], res);

    state->registerFile.writeReg(0xF, msb);
}

void InstructionExecutor::ex_9XY0()
{
    uint8_t vxVal, vyVal;

    state->registerFile.readReg(args[0], &vxVal);
    state->registerFile.readReg(args[1], &vyVal);

    if(vxVal != vyVal)
        state->programCounter += 2;
}

void InstructionExecutor::ex_ANNN()
{
    state->indexReg = args[0];
}

void InstructionExecutor::ex_BNNN()
{
    uint8_t val;

    state->registerFile.readReg(0x0, &val);

    val += args[0];

    state->programCounter = val;
}

void InstructionExecutor::ex_CXNN()
{
    uint8_t val = (rand() % 256) & args[1];

    state->registerFile.writeReg(args[0], val);
}

void InstructionExecutor::ex_DXYN()
{
    uint8_t x, y, n = args[2];
    uint8_t sprite[16];

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
    state->registerFile.writeReg(args[0], state->delayTimer);
}

void InstructionExecutor::ex_FX0A()
{
    // Implementation for opcode FX0A
}

void InstructionExecutor::ex_FX15()
{
    uint8_t vxVal;

    state->registerFile.readReg(args[0], &vxVal);

    state->delayTimer = vxVal;
}

void InstructionExecutor::ex_FX18()
{
    //sound timer not implemented
}

void InstructionExecutor::ex_FX1E()
{
    uint8_t vxVal;

    state->registerFile.readReg(args[0], &vxVal);

    state->indexReg += vxVal;
}

void InstructionExecutor::ex_FX29()
{
    uint8_t vxVal;

    state->registerFile.readReg(args[0], &vxVal);

    state->indexReg = Emulator::FONT_LOAD_ADDR + vxVal;
}

void InstructionExecutor::ex_FX33()
{
    uint8_t vxVal;
    uint8_t bcdDigits[3];
    
    state->registerFile.readReg(args[0], &vxVal);

    bcdDigits[0] = vxVal / 100;
    vxVal       -= bcdDigits[0] * 100;
    bcdDigits[1] = vxVal / 10;
    vxVal       -= bcdDigits[1] * 10;
    bcdDigits[2] = vxVal;

    state->memory.write(state->indexReg, bcdDigits, sizeof(bcdDigits));
}

void InstructionExecutor::ex_FX55()
{
    uint8_t x = args[0], regVal;

    for(uint8_t reg = 0; reg <= x; reg++)
    {
        state->registerFile.readReg(reg, &regVal);
        state->memory.write(state->indexReg, &regVal, 1);
        state->indexReg++;
    }
}

void InstructionExecutor::ex_FX65()
{
    uint8_t x = args[0], memVal;

    for(uint8_t reg = 0; reg <= x; reg++)
    {
        state->memory.read(state->indexReg, &memVal, 1);
        state->registerFile.writeReg(reg, memVal);
        state->indexReg++;
    }
}