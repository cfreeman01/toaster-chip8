#include <emulator/emulator.h>
#include <emulator/instructionExecutor.h>
#include <functional>
#include <iostream>
using namespace std;

Emulator::Emulator()
{
    function<void()> exInstructionPtr = bind(&Emulator::exInstruction, this);
    function<void()> renderPtr        = bind(&Emulator::render,        this);

    insTimer    = EventTimer(exInstructionPtr, INS_RATE_MS);
    renderTimer = EventTimer(renderPtr,        RENDER_RATE_MS);
}

void Emulator::update(double deltaTimeMs)
{
    insTimer.update(deltaTimeMs);
    renderTimer.update(deltaTimeMs);
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