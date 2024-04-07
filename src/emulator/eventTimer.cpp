#include <emulator/eventTimer.h>
#include <iostream>

void EventTimer::update(double deltaTimeMs)
{
    curTimeMs += deltaTimeMs;

    while(curTimeMs >= rateMs)
    {
        curTimeMs -= rateMs;
        func();
    }
}