#pragma once
#include <cstdint>
#include <map>
#include "emulator/chipInstruction.h"
#include "emulator/display.h"
#include "emulator/registerFile.h"
#include "emulator/memory.h"

class Emulator
{
    public:
    void executeInstruction(uint16_t opcode);

    private:
    Display display;
    RegisterFile registerFile;
    Memory memory;

    void ex_00E0(uint16_t* args);
    void ex_DXYN(uint16_t* args);

    typedef void(Emulator::*InsPtr)(uint16_t*);

    std::map<CHIPInstruction, InsPtr> instructionMap = 
    {
        {CHIPInstruction::_00E0, &Emulator::ex_00E0},
        {CHIPInstruction::_DXYN, &Emulator::ex_DXYN},
    };
};