#pragma once
#include <cstdint>

class Display
{
    public:
    static const uint32_t NUM_COLS     = 64;
    static const uint32_t NUM_ROWS     = 32;
    static const uint32_t SPRITE_WIDTH = 8;

    bool drawSprite(uint32_t x, uint32_t y, uint8_t* sprite, uint32_t height);
    void clear();
    const uint64_t* const getDisplayData();

    private:
    uint64_t displayData[NUM_ROWS] = {0};

    bool xorRow(uint32_t x, uint32_t y, uint8_t spriteRow);
};