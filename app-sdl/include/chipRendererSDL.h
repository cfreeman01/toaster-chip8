#pragma once
#include <chipRenderer.h>
#include <SDL2/SDL.h>

class CHIPRendererSDL: public CHIPRenderer
{
    public:
    EmuErrorCode render(const uint64_t* displayData);

    CHIPRendererSDL(SDL_Window* window);
    CHIPRendererSDL();
    ~CHIPRendererSDL();
    CHIPRendererSDL(const CHIPRendererSDL& other)              = delete;
    CHIPRendererSDL& operator=(const CHIPRendererSDL & other)  = delete;
    CHIPRendererSDL(CHIPRendererSDL && other);
    CHIPRendererSDL& operator=(CHIPRendererSDL && other);

    private:
    SDL_Renderer* renderer = nullptr;
    SDL_Texture*  texture  = nullptr; 
};