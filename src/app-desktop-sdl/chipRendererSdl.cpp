#include "app-desktop-sdl/chipRendererSdl.h"
#include "emulator/display.h"

CHIPRendererSDL::CHIPRendererSDL(SDL_Window* window)
{
    this->window = window;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

    texture  = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, Display::WIDTH, Display::HEIGHT);
}

CHIPRendererSDL::~CHIPRendererSDL()
{
    SDL_DestroyRenderer(renderer);
}

EmuErrorCode CHIPRendererSDL::render(const uint64_t* displayData)
{
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    for (int i = 0; i < Display::HEIGHT; i++)
        SDL_RenderDrawPoint(renderer, i, i);

    SDL_SetRenderTarget(renderer, NULL);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, texture, NULL, NULL);

	SDL_RenderPresent(renderer);

    return EmuErrorCode::SUCCESS;
}