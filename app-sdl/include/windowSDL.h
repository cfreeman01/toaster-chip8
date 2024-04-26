#pragma once
#include <SDL2/SDL.h>
#include <string>

class WindowSDL
{
    public:
    SDL_Window* getWindow() { return window; }

    WindowSDL(std::string windowName, uint32_t windowWidth, uint32_t windowHeight);
    WindowSDL();
    ~WindowSDL();
    WindowSDL(const WindowSDL& other)              = delete;
    WindowSDL& operator=(const WindowSDL & other)  = delete;
    WindowSDL(WindowSDL && other);
    WindowSDL& operator=(WindowSDL && other);

    private:
    SDL_Window* window = nullptr;
};