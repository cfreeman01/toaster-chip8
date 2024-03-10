#include <emulator/registerFile.h>

uint8_t RegisterFile::readReg(Register reg)
{
    return registers[static_cast<int>(reg)];
}

void RegisterFile::writeReg(Register reg, uint8_t val)
{
    registers[static_cast<int>(reg)] = val;
}