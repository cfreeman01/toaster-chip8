#pragma once
#include "CppUTest/SimpleString.h"
#include "emulator/emuErrorCode.h"

static SimpleString StringFrom(EmuErrorCode value)
{
    return EmuErrorCodeStrings[static_cast<int>(value)];
}