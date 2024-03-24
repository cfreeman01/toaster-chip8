#pragma once
#include "emulator/chipRenderer.h"
#include <SDL2/SDL.h>

class CHIPRendererSDL: public CHIPRenderer
{
    public:
    CHIPRendererSDL(SDL_Window* window);
    ~CHIPRendererSDL();

    EmuErrorCode render(const uint64_t* displayData);

    private:
    SDL_Window*   window;
    SDL_Renderer* renderer;
    SDL_Texture*  texture;
};