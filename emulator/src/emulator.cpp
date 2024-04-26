#include <emulator.h>
#include <instructionExecutor.h>
#include <functional>
#include <iostream>
#include <font.h>
using namespace std;

Emulator::Emulator()
{
    function<void()> exInstructionPtr = bind(&Emulator::exInstruction, this);
    function<void()> renderPtr        = bind(&Emulator::render,        this);
    function<void()> decDelayTimerPtr = bind(&Emulator::decDelayTimer, this);

    insTimer    = EventTimer(exInstructionPtr, INS_RATE_MS);
    renderTimer = EventTimer(renderPtr,        RENDER_RATE_MS);
    delayTimer  = EventTimer(decDelayTimerPtr, TIMER_RATE_MS);

    loadFont();
}

void Emulator::update(double deltaTimeMs)
{
    insTimer.update(deltaTimeMs);
    renderTimer.update(deltaTimeMs);
    delayTimer.update(deltaTimeMs);
}

void Emulator::loadROM(std::vector<char> & ROMbuffer)
{
    state.memory.write(ROM_LOAD_ADDR, (uint8_t*)(ROMbuffer.data()), ROMbuffer.size());
    
    state.programCounter = ROM_LOAD_ADDR;
}

void Emulator::reset()
{
    state = EmulatorState();
    curTimeMs = 0;
    loadFont();
}

void Emulator::render()
{
    renderer->render(state.display.getDisplayData());
}

void Emulator::exInstruction()
{
    uint8_t  bytes[2];
    uint16_t ins = 0x0000;

    state.memory.read(state.programCounter, bytes, 2);

    ins |= bytes[0] << 8 | bytes[1];

    InstructionExecutor::execute(ins, state);
}

void Emulator::loadFont()
{
    state.memory.write(FONT_LOAD_ADDR, font, sizeof(font));
}

void Emulator::decDelayTimer()
{
    if(state.delayTimer > 0)
        state.delayTimer--;
}

void Emulator::keyEvent(uint8_t keyVal, bool pressed)
{
    uint16_t keysUpdate = 0x1 << keyVal;

    if(pressed)
        state.keys |= keysUpdate;
    else
        state.keys &= (!keysUpdate);
}