#pragma once

enum class EmuErrorCode 
{
    SUCCESS = 0,
    REG_RANGE,
    MEM_RANGE
};

static const char *EmuErrorCodeStrings[] =
{
    "SUCCESS",
    "REG_RANGE",
    "MEM_RANGE"
};