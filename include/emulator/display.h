#pragma once
#include <cstdint>

class Display
{
    public:
    static const uint32_t WIDTH        = 64;
    static const uint32_t HEIGHT       = 32;
    static const uint32_t SPRITE_WIDTH = 8;

    bool drawSprite(uint8_t x, uint8_t y, uint8_t* sprite, uint8_t height);
    void clear();
    const uint64_t* const getDisplayData();

    private:
    uint64_t displayData[HEIGHT] = {0};

    bool xorRow(uint8_t x, uint8_t y, uint8_t spriteRow);
};