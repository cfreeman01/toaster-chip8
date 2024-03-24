#pragma once
#include <SDL2/SDL.h>
#include <string>

class SDLContext
{
    public:
    SDLContext(std::string windowName, uint32_t windowWidth, uint32_t windowHeight);
    ~SDLContext();
    SDL_Window* getWindow() { return window; }

    private:
    SDL_Window* window;
};