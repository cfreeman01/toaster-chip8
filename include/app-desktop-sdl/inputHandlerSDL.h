#pragma once
#include <SDL2/SDL.h>

class InputHandlerSDL
{
    public:
    static const uint8_t     NUM_KEYS = 16;
    static const SDL_KeyCode keyValMap[NUM_KEYS];

    static bool getKeyEvent(SDL_Event event, uint8_t & key, bool & pressed);
};