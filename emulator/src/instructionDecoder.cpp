#include "instructionDecoder.h"

CHIPInstruction InstructionDecoder::decode(uint16_t opcode, uint16_t* args)
{
    CHIPInstruction ins = CHIPInstruction::_INVALID;

    uint16_t nnn = opcode & 0x0FFF;
	uint16_t nn =  opcode & 0x00FF;
	uint16_t n =   opcode & 0x000F;
	uint16_t x =   (opcode & 0x0F00) >> 8;
	uint16_t y =   (opcode & 0x00F0) >> 4;

    switch(opcode & 0xF000)
    {
        case 0x0000:
        ins = decode0(opcode);
        break;

        case 0x1000:
        ins = CHIPInstruction::_1NNN;
        args[0] = nnn;
        break;

        case 0x2000:
        ins = CHIPInstruction::_2NNN;
        args[0] = nnn;
        break;

        case 0x3000:
        ins = CHIPInstruction::_3XNN;
        args[0] = x;
        args[1] = nn;
        break;

        case 0x4000:
        ins = CHIPInstruction::_4XNN;
        args[0] = x;
        args[1] = nn;
        break;

        case 0x5000:
        ins = CHIPInstruction::_5XY0;
        args[0] = x;
        args[1] = y;
        break;

        case 0x6000:
        ins = CHIPInstruction::_6XNN;
        args[0] = x;
        args[1] = nn;
        break;

        case 0x7000:
        ins = CHIPInstruction::_7XNN;
        args[0] = x;
        args[1] = nn;
        break;

        case 0x8000:
        ins = decode8(opcode);
        args[0] = x;
        args[1] = y;
        break;

        case 0x9000:
        ins = CHIPInstruction::_9XY0;
        args[0] = x;
        args[1] = y;
        break;

        case 0xA000:
        ins = CHIPInstruction::_ANNN;
        args[0] = nnn;
        break;

        case 0xB000:
        ins = CHIPInstruction::_BNNN;
        args[0] = nnn;
        break;

        case 0xC000:
        ins = CHIPInstruction::_CXNN;
        args[0] = x;
        args[1] = nn;
        break;

        case 0xD000:
        ins = CHIPInstruction::_DXYN;
        args[0] = x;
        args[1] = y;
        args[2] = n;
        break;

        case 0xE000:
        ins = decodeE(opcode);
        args[0] = x;
        break;

        case 0xF000:
        ins = decodeF(opcode);
        args[0] = x;
        break;
    }

    return ins;
}

CHIPInstruction InstructionDecoder::decode0(uint16_t opcode)
{
    CHIPInstruction ins = CHIPInstruction::_INVALID;

    switch(opcode)
    {
        case 0x00E0:
        ins = CHIPInstruction::_00E0;
        break;

        case 0x00EE:
        ins = CHIPInstruction::_00EE;
        break;
    }

    return ins;
}

CHIPInstruction InstructionDecoder::decode8(uint16_t opcode)
{
    CHIPInstruction ins = CHIPInstruction::_INVALID;

    switch(opcode & 0x000F)
    {
        case 0x0000:
        ins = CHIPInstruction::_8XY0;
        break;

        case 0x0001:
        ins = CHIPInstruction::_8XY1;
        break;

        case 0x0002:
        ins = CHIPInstruction::_8XY2;
        break;

        case 0x0003:
        ins = CHIPInstruction::_8XY3;
        break;

        case 0x0004:
        ins = CHIPInstruction::_8XY4;
        break;

        case 0x0005:
        ins = CHIPInstruction::_8XY5;
        break;

        case 0x0006:
        ins = CHIPInstruction::_8XY6;
        break;

        case 0x0007:
        ins = CHIPInstruction::_8XY7;
        break;

        case 0x000E:
        ins = CHIPInstruction::_8XYE;
        break;
    }

    return ins;
}

CHIPInstruction InstructionDecoder::decodeE(uint16_t opcode)
{
    CHIPInstruction ins = CHIPInstruction::_INVALID;

    switch(opcode & 0x00FF)
    {
        case 0x009E:
        ins = CHIPInstruction::_EX9E;
        break;

        case 0x00A1:
        ins = CHIPInstruction::_EXA1;
        break;
    }

    return ins;
}

CHIPInstruction InstructionDecoder::decodeF(uint16_t opcode)
{
    CHIPInstruction ins = CHIPInstruction::_INVALID;

    switch(opcode & 0x00FF)
    {
        case 0x0007:
        ins = CHIPInstruction::_FX07;
        break;

        case 0x000A:
        ins = CHIPInstruction::_FX0A;
        break;

        case 0x0015:
        ins = CHIPInstruction::_FX15;
        break;

        case 0x0018:
        ins = CHIPInstruction::_FX18;
        break;

        case 0x001E:
        ins = CHIPInstruction::_FX1E;
        break;

        case 0x0029:
        ins = CHIPInstruction::_FX29;
        break;

        case 0x0033:
        ins = CHIPInstruction::_FX33;
        break;

        case 0x0055:
        ins = CHIPInstruction::_FX55;
        break;

        case 0x0065:
        ins = CHIPInstruction::_FX65;
        break;
    }

    return ins;
}