#include "app-desktop-sdl/chipRendererSdl.h"
#include "emulator/display.h"

CHIPRendererSDL::CHIPRendererSDL(SDL_Window* window)
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

    texture  = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, Display::WIDTH, Display::HEIGHT);
}

CHIPRendererSDL::~CHIPRendererSDL()
{
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
}

EmuErrorCode CHIPRendererSDL::render(const uint64_t* displayData)
{
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    uint64_t mask = 0x80'00'00'00'00'00'00'00;
    for (int row = 0; row < Display::HEIGHT; row++)
        for(int col = 0; col < Display::WIDTH; col++)
            if((mask >> col) & displayData[row])
                SDL_RenderDrawPoint(renderer, col, row);

    SDL_SetRenderTarget(renderer, NULL);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    
    SDL_RenderPresent(renderer);

    return EmuErrorCode::SUCCESS;
}