#pragma once
#include "emuErrorCode.h"
#include <cstdlib>
#include "display.h"

class CHIPRenderer
{
    public:
    virtual EmuErrorCode render(const uint64_t* displayData) = 0;
};