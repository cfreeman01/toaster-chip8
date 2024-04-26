#include <registerFile.h>

EmuErrorCode RegisterFile::readReg(uint8_t reg, uint8_t* val)
{
    if(reg >= NUM_REGS)
        return EmuErrorCode::REG_RANGE;

    *val = registers[reg];

    return EmuErrorCode::SUCCESS;
}

EmuErrorCode RegisterFile::writeReg(uint8_t reg, uint8_t val)
{
    if(reg >= NUM_REGS)
        return EmuErrorCode::REG_RANGE;

    registers[reg] = val;

    return EmuErrorCode::SUCCESS;
}