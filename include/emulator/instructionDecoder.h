#pragma once
#include "emulator/chipInstruction.h"
#include <cstdint>

class InstructionDecoder
{
    public:
    static CHIPInstruction decode(uint16_t opcode, uint16_t* args);

    private:
    static CHIPInstruction decode0(uint16_t opcode);
    static CHIPInstruction decode8(uint16_t opcode);
    static CHIPInstruction decodeE(uint16_t opcode);
    static CHIPInstruction decodeF(uint16_t opcode);
};