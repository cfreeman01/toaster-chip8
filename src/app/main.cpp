#include "emulator/emulator.h"

int main(void)
{
    Emulator emulator;

    emulator.executeInstruction(0x00E0);
    emulator.executeInstruction(0xD123);
}