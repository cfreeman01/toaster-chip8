#include "app-desktop-sdl/sdlContext.h"
#include <iostream>

SDLContext::SDLContext(std::string windowName, uint32_t windowWidth, uint32_t windowHeight)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) >= 0) 
    {
        window = SDL_CreateWindow(windowName.c_str(), 
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
             windowWidth, windowHeight, 
             SDL_WINDOW_OPENGL);
    }
}

SDLContext::~SDLContext()
{
    SDL_DestroyWindow(window);
}