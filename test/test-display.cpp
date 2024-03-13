#include "CppUTest/TestHarness.h"
#include "emulator/display.h"
#include "emuErrorCodeUtils.h"

TEST_GROUP(DisplayTests){

    Display display;
    uint64_t empty[Display::NUM_ROWS] = {0};
    uint32_t displaySizeBytes = 8 * 32;

    void setup()
    {
        display = Display();
    }

    void teardown()
    {

    }
};

TEST(DisplayTests, WriteAll1Middle)
{
    uint64_t expected[Display::NUM_ROWS] = 
    {
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'FF'00'00'00'00,
        0x00'00'00'FF'00'00'00'00,
        0x00'00'00'FF'00'00'00'00,
        0x00'00'00'FF'00'00'00'00,
        0x00'00'00'FF'00'00'00'00,
        0x00'00'00'FF'00'00'00'00,
        0x00'00'00'FF'00'00'00'00,
        0x00'00'00'FF'00'00'00'00,
        //rest zero
    };

    const uint32_t spriteHeight = 8;
    const uint32_t spriteX      = 24;
    const uint32_t spriteY      = 8;
    uint8_t sprite[spriteHeight] = 
    {
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF
    };

    bool ret = display.drawSprite(spriteX, spriteY, sprite, spriteHeight);
    CHECK_EQUAL(0, ret);
    MEMCMP_EQUAL(expected, display.getDisplayData(), displaySizeBytes);

    display.clear();
    MEMCMP_EQUAL(empty, display.getDisplayData(), displaySizeBytes);
}