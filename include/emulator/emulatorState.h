#pragma once
#include "display.h"
#include "registerFile.h"
#include "memory.h"
#include "chipRenderer.h"
#include <stack>

typedef struct EmulatorState
{
    Memory               memory;
    RegisterFile         registerFile;
    Display              display;
    uint16_t             programCounter;
    uint16_t             indexReg;
    std::stack<uint16_t> sysStack;
    uint8_t              delayTimer;
} EmulatorState;