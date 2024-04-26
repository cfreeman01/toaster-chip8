#include "chipRendererMock.h"

EmuErrorCode CHIPRendererMock::render(const uint64_t* displayData)
{
    return EmuErrorCode::SUCCESS;
}