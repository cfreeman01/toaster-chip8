#pragma once
#include "CppUTest/SimpleString.h"
#include "emulator/emuErrorCode.h"
#include "emulator/chipInstruction.h"

static SimpleString StringFrom(EmuErrorCode value)
{
    return EmuErrorCodeStrings[static_cast<int>(value)];
}

static SimpleString StringFrom(CHIPInstruction value)
{
    return CHIPInstructionStrings[static_cast<int>(value)];
}