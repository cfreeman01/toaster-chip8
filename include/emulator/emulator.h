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
    void keyEvent(uint8_t keyVal, bool pressed);

    static constexpr uint16_t ROM_LOAD_ADDR   = 0x200;
    static constexpr uint16_t FONT_LOAD_ADDR  = 0x00;
    static constexpr double   INS_RATE_MS     = 1.428;
    static constexpr double   TIMER_RATE_MS   = 16.67;
    static constexpr double   RENDER_RATE_MS  = 16.67;

    private:
    EmulatorState  state;
    CHIPRenderer*  renderer   = nullptr;
    double         curTimeMs  = 0;

    EventTimer insTimer;
    EventTimer renderTimer;
    EventTimer delayTimer;

    void render();
    void exInstruction();
    void loadFont();
    void decDelayTimer();
};