#include <emulator/memory.h>
#include <cstring>

EmuErrorCode Memory::read(uint16_t addr, uint8_t* dest, uint32_t len)
{
    if(addr + len > MEM_SIZE)
        return EmuErrorCode::MEM_RANGE;

    memcpy(dest, mem + addr, len);

    return EmuErrorCode::SUCCESS;
}

EmuErrorCode Memory::write(uint16_t addr, uint8_t* src, uint32_t len)
{
    if(addr + len > MEM_SIZE)
        return EmuErrorCode::MEM_RANGE;

    memcpy(mem + addr, src, len);

    return EmuErrorCode::SUCCESS;
}