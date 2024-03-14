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
    const uint32_t spriteHeight = 8;
    const uint32_t spriteX      = 24;
    const uint32_t spriteY      = 8;

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
    CHECK_EQUAL(false, ret);
    MEMCMP_EQUAL(expected, display.getDisplayData(), displaySizeBytes);

    display.clear();
    MEMCMP_EQUAL(empty, display.getDisplayData(), displaySizeBytes);
}

TEST(DisplayTests, WritePatternMiddle)
{
    const uint32_t spriteHeight = 8;
    const uint32_t spriteX      = 24;
    const uint32_t spriteY      = 8;

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
        0x00'00'00'88'00'00'00'00,
        0x00'00'00'88'00'00'00'00,
        0x00'00'00'88'00'00'00'00,
        0x00'00'00'88'00'00'00'00,
        0x00'00'00'88'00'00'00'00,
        0x00'00'00'88'00'00'00'00,
        0x00'00'00'88'00'00'00'00,
        0x00'00'00'88'00'00'00'00,
        //rest zero
    };

    uint8_t sprite1[spriteHeight] = 
    {
        0xAA,
        0xAA,
        0xAA,
        0xAA,
        0xAA,
        0xAA,
        0xAA,
        0xAA
    };

    uint8_t sprite2[spriteHeight] = 
    {
        0x22,
        0x22,
        0x22,
        0x22,
        0x22,
        0x22,
        0x22,
        0x22
    };

    bool ret = display.drawSprite(spriteX, spriteY, sprite1, spriteHeight);
    CHECK_EQUAL(false, ret);

    ret = display.drawSprite(spriteX, spriteY, sprite2, spriteHeight);
    CHECK_EQUAL(true, ret);
    MEMCMP_EQUAL(expected, display.getDisplayData(), displaySizeBytes);
}

TEST(DisplayTests, WriteAll1RightEdge)
{
    const uint32_t spriteHeight = 8;
    const uint32_t spriteX      = 60;
    const uint32_t spriteY      = 8;

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
        0x00'00'00'00'00'00'00'0F,
        0x00'00'00'00'00'00'00'0F,
        0x00'00'00'00'00'00'00'0F,
        0x00'00'00'00'00'00'00'0F,
        0x00'00'00'00'00'00'00'0F,
        0x00'00'00'00'00'00'00'0F,
        0x00'00'00'00'00'00'00'0F,
        0x00'00'00'00'00'00'00'0F,
        //rest zero
    };

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
    CHECK_EQUAL(false, ret);
    MEMCMP_EQUAL(expected, display.getDisplayData(), displaySizeBytes);
}

TEST(DisplayTests, WriteAll1BottomEdge)
{
    const uint32_t spriteHeight = 8;
    const uint32_t spriteX      = 24;
    const uint32_t spriteY      = 28;

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
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
        0x00'00'00'00'00'00'00'00,
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
    };

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
    CHECK_EQUAL(false, ret);
    MEMCMP_EQUAL(expected, display.getDisplayData(), displaySizeBytes);
}