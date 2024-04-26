#pragma once
#include "CppUTest/SimpleString.h"
#include "emuErrorCode.h"
#include "chipInstruction.h"

static SimpleString StringFrom(EmuErrorCode value)
{
    return EmuErrorCodeStrings[static_cast<int>(value)];
}

static SimpleString StringFrom(CHIPInstruction value)
{
    return CHIPInstructionStrings[static_cast<int>(value)];
}