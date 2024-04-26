#include "windowSDL.h"
#include <iostream>

WindowSDL::WindowSDL()
{

}

WindowSDL::WindowSDL(std::string windowName, uint32_t windowWidth, uint32_t windowHeight)
{
    window = SDL_CreateWindow(windowName.c_str(), 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        windowWidth, windowHeight, 
        SDL_WINDOW_OPENGL);
}

WindowSDL::~WindowSDL()
{
    if(window != nullptr)
        SDL_DestroyWindow(window);
}

WindowSDL::WindowSDL(WindowSDL && other)
{
    this->window = other.window;
    other.window = nullptr;
}

WindowSDL& WindowSDL::operator=(WindowSDL && other)
{
    this->window = other.window;
    other.window = nullptr;

    return *this;
}