#pragma once
#include "chipDisplay.h"
#include "registerFile.h"
#include "chipMemory.h"
#include "chipRenderer.h"
#include <stack>

typedef struct EmulatorState
{
    CHIPMemory               memory;
    RegisterFile         registerFile;
    CHIPDisplay              display;
    uint16_t             programCounter;
    uint16_t             indexReg;
    std::stack<uint16_t> sysStack;
    uint8_t              delayTimer;
    uint16_t             keys;
} EmulatorState;