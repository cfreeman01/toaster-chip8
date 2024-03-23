#include <iostream>
#include "emulator/emulator.h"
#include "emulator/instructionDecoder.h"

void Emulator::executeInstruction(uint16_t opcode)
{
    uint16_t args[3];

    CHIPInstruction ins = InstructionDecoder::decode(opcode, args);

    (this->*instructionMap[ins])(args);
}

void Emulator::ex_00E0(uint16_t* args)
{
    std::cout << "clearing screen" << std::endl;
    display.clear();
}

void Emulator::ex_DXYN(uint16_t* args)
{
    std::cout << "drawing sprite " << args[0] << " " << args[1] << " " << args[2] << std::endl;
}