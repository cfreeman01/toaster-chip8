#include "app-desktop-sdl/inputHandlerSDL.h"

const SDL_KeyCode InputHandlerSDL::keyValMap[NUM_KEYS]
    {
        SDLK_x, //0
        SDLK_1, //1
        SDLK_2, //etc...
        SDLK_3,
        SDLK_q,
        SDLK_w,
        SDLK_e,
        SDLK_a,
        SDLK_s,
        SDLK_d,
        SDLK_z,
        SDLK_c,
        SDLK_4,
        SDLK_r,
        SDLK_f,
        SDLK_v
    };

bool InputHandlerSDL::getKeyEvent(SDL_Event event, uint8_t & key, bool & pressed)
{
    if(event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
    {
        if(event.type == SDL_KEYDOWN)
            pressed = true;
        else
            pressed = false;

        for(uint8_t keyNum = 0; keyNum < NUM_KEYS; keyNum++)
            if(event.key.keysym.sym == keyValMap[keyNum])
            {
                key = keyNum;
                return true;
            }
    }

    return false;
}