#pragma once
#include <SDL2/SDL.h>
#include <string>

class SDLWindow
{
    public:
    SDL_Window* getWindow() { return window; }

    SDLWindow(std::string windowName, uint32_t windowWidth, uint32_t windowHeight);
    SDLWindow();
    ~SDLWindow();
    SDLWindow(const SDLWindow& other)              = delete;
    SDLWindow& operator=(const SDLWindow & other)  = delete;
    SDLWindow(SDLWindow && other);
    SDLWindow& operator=(SDLWindow && other);

    private:
    SDL_Window* window = nullptr;
};