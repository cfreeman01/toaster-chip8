#pragma once
#include <cstdint>
#include <map>
#include "chipInstruction.h"
#include "display.h"
#include "registerFile.h"
#include "memory.h"
#include "chipRenderer.h"

class Emulator
{
    public:
    void setRenderer(CHIPRenderer & renderer) { this->renderer = &renderer; }

    private:
    CHIPRenderer* renderer;
    Display display;
    RegisterFile registerFile;
    Memory memory;

    void executeInstruction(uint16_t opcode);
    void ex_00E0(uint16_t* args);
    void ex_DXYN(uint16_t* args);

    typedef void(Emulator::*InsPtr)(uint16_t*);

    std::map<CHIPInstruction, InsPtr> instructionMap = 
    {
        {CHIPInstruction::_00E0, &Emulator::ex_00E0},
        {CHIPInstruction::_DXYN, &Emulator::ex_DXYN},
    };
};