#pragma once
#include "emulator/chipRenderer.h"

class CHIPRendererMock: public CHIPRenderer
{
    public:
    EmuErrorCode render(const uint64_t* displayData);
};
