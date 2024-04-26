#pragma once
#include "emuErrorCode.h"
#include <cstdlib>
#include "chipDisplay.h"

class CHIPRenderer
{
    public:
    virtual EmuErrorCode render(const uint64_t* displayData) = 0;
};