#include <chipDisplay.h>
#include <stdio.h>

bool CHIPDisplay::drawSprite(uint8_t x, uint8_t y, uint8_t* sprite, uint8_t height)
{
    bool pixelUnset = false;
    x = x % WIDTH;
    y = y % HEIGHT;

    for(uint8_t i = 0; (i < height) && (i+y < HEIGHT); i++)
        if(xorRow(x, y+i, sprite[i]))
            pixelUnset = true;

    return pixelUnset;
}

void CHIPDisplay::clear()
{
    for(uint8_t i = 0; i < HEIGHT; i++)
        displayData[i] = 0;
}

const uint64_t* const CHIPDisplay::getDisplayData()
{
    return (const uint64_t* const)displayData;
}

bool CHIPDisplay::xorRow(uint8_t x, uint8_t y, uint8_t spriteRow)
{
    bool pixelUnset = false;

    uint64_t spriteRowExt = (uint64_t)spriteRow;
    spriteRowExt <<= (WIDTH) - SPRITE_WIDTH;
    spriteRowExt >>= x;

    for(uint8_t i = 0; i < SPRITE_WIDTH && ((x+i) < WIDTH); i++)
    {
        uint64_t curBitSet = (0x80'00'00'00'00'00'00'00 >> (x + i));
        uint64_t displayRowTemp = displayData[y] & curBitSet;
        uint64_t spriteRowTemp  = spriteRowExt   & curBitSet;

        if(displayRowTemp && spriteRowTemp)
            pixelUnset = true;

        displayData[y] ^= spriteRowTemp;
    }
    
    return pixelUnset;
}