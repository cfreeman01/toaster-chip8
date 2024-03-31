#include "app-desktop-sdl/sdlWindow.h"
#include <iostream>

SDLWindow::SDLWindow()
{

}

SDLWindow::SDLWindow(std::string windowName, uint32_t windowWidth, uint32_t windowHeight)
{
    window = SDL_CreateWindow(windowName.c_str(), 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        windowWidth, windowHeight, 
        SDL_WINDOW_OPENGL);
}

SDLWindow::~SDLWindow()
{
    if(window != nullptr)
        SDL_DestroyWindow(window);
}

SDLWindow::SDLWindow(SDLWindow && other)
{
    this->window = other.window;
    other.window = nullptr;
}

SDLWindow& SDLWindow::operator=(SDLWindow && other)
{
    this->window = other.window;
    other.window = nullptr;

    return *this;
}