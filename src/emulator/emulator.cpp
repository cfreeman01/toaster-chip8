#include <emulator/emulator.h>
using namespace std;

void test()
{
    cout << "hello world" << endl;
}

Emulator::Emulator()
{
    testTimer = EventTimer(test, 1000.0);
}

void Emulator::update(double deltaTimeMs)
{
    testTimer.update(deltaTimeMs);
}

void Emulator::loadROM(std::vector<char> & ROMbuffer)
{

}

void Emulator::reset()
{
    state = EmulatorState();
    curTimeMs = 0;
}