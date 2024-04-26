#pragma once
#include <cstdint>
#include "emuErrorCode.h"

class RegisterFile
{
    public:
    static const uint8_t NUM_REGS = 16;
    EmuErrorCode readReg(uint8_t reg, uint8_t* val);
    EmuErrorCode writeReg(uint8_t reg, uint8_t val);

    private:
    uint8_t registers[NUM_REGS] = {0};
};