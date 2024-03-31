#pragma once
#include <cstdint>

class EventTimer
{
    public:
    EventTimer();
    EventTimer(void (*func)(), double rateMs): func(func), rateMs(rateMs) {};
    void update(double deltaTimeMs);

    private:
    void     (*func)();
    double   rateMs;
    double   curTimeMs = 0.0;
};