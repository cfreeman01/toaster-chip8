#include "emulator/emulator.h"
#include "app-desktop-sdl/chipRendererSdl.h"
#include "app-desktop-sdl/sdlContext.h"

int main(void)
{
    const uint32_t WINDOW_SCALE = 20;

    SDLContext sdlContext("CHIP8", Display::WIDTH * WINDOW_SCALE, Display::HEIGHT * WINDOW_SCALE);
    
    if(sdlContext.getWindow() == nullptr)
        return 1;

    CHIPRendererSDL renderer(sdlContext.getWindow());
    renderer.render(nullptr);

    SDL_Event sdlEvent;
    while(true)
    {
        if (SDL_PollEvent(&sdlEvent))
            if (sdlEvent.type == SDL_QUIT)
                break;
    }

    return 0;
}