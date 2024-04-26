#pragma once
#include <cstdint>
#include "emuErrorCode.h"

class CHIPMemory
{
    public:
    static const uint32_t MEM_SIZE = 4096;
    EmuErrorCode read(uint16_t addr, uint8_t* dest, uint32_t len);
    EmuErrorCode write(uint16_t addr, uint8_t* src, uint32_t len);

    private:
    uint8_t mem[MEM_SIZE] = {0};
};