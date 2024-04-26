#pragma once
#include <cstdint>
#include <functional>

class EventTimer
{
    public:
    EventTimer() {};
    EventTimer(std::function<void()> func, double rateMs): func(func), rateMs(rateMs) {};
    void update(double deltaTimeMs);

    private:
    std::function<void()> func;

    double rateMs;
    double curTimeMs = 0.0;
};