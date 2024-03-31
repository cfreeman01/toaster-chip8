#pragma once
#include "emulatorState.h"
#include "chipRenderer.h"
#include "eventTimer.h"
#include <vector>
#include <iostream>

class Emulator
{
    public:
    Emulator();
    void update(double deltaTimeMs);
    void loadROM(std::vector<char> & ROMbuffer);
    void reset();
    void setRenderer(CHIPRenderer* renderer) { this->renderer  = renderer;  }
    void setInsRate(double insRateMs)         { this->insRateMs = insRateMs; }

    private:
    EmulatorState state;
    CHIPRenderer* renderer;
    double        curTimeMs  = 0;
    double        insRateMs  = 1.428;
    EventTimer    testTimer;
};