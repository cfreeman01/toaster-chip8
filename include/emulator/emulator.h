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

    private:
    EmulatorState  state;
    CHIPRenderer*  renderer   = nullptr;
    double         curTimeMs  = 0;

    EventTimer insTimer;
    EventTimer renderTimer;

    const uint16_t ROM_LOAD_ADDR  = 0x200;
    const double   INS_RATE_MS    = 1.428;
    const double   RENDER_RATE_MS = 16.67;

    void render();
    void exInstruction();
};