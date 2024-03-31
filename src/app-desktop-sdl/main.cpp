#include "app-desktop-sdl/chipRendererSdl.h"
#include "app-desktop-sdl/sdlWindow.h"
#include "emulator/emulator.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sys/time.h>

using namespace std;

void   printUsage();
int    readROMFile(char* path, vector<char> & buffer);
double getTimeMs();

int main(int argc, char* argv[])
{
    Emulator        emulator;
    vector<char>    ROMbuffer;
    const uint32_t  WINDOW_SCALE = 20;
    SDLWindow       sdlWindow;
    CHIPRendererSDL renderer;
    SDL_Event       sdlEvent;
    double          curTimeMs;
    double          prevTimeMs;
    double          deltaTimeMs;

    if(argc != 2 && argc !=3)
    {
        printUsage();
        return 1;
    }
    
    if(argc == 3)
    {
        uint32_t insRate = stoul(string(argv[2]));
        emulator.setInsRate(insRate);
    }

    if(readROMFile(argv[1], ROMbuffer))
    {
        cout << "ERROR: Could not read ROM file." << endl;
        return 1;
    }

    emulator.loadROM(ROMbuffer);

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
    {
        cout << "ERROR: Could not initialize SDL." << endl;
        return 1;
    }

    sdlWindow = SDLWindow("CHIP8", Display::WIDTH * WINDOW_SCALE, Display::HEIGHT * WINDOW_SCALE);
    
    if(sdlWindow.getWindow() == nullptr)
    {
        cout << "ERROR: Could not create SDL window." << endl;
        return 1;
    }

    renderer = CHIPRendererSDL(sdlWindow.getWindow());

    curTimeMs = prevTimeMs = getTimeMs();
    while(true)
    {
        if (SDL_PollEvent(&sdlEvent))
            if (sdlEvent.type == SDL_QUIT)
                break;

        curTimeMs   = getTimeMs();
        deltaTimeMs = curTimeMs - prevTimeMs;
        prevTimeMs = curTimeMs;
        emulator.update(deltaTimeMs);
    }

    return 0;
}

void printUsage()
{
    cout                                                 << endl;
    cout << "==============CHIP8 Emulator==============" << endl;
    cout << "./CHIP8 <ROM path> <instructions per sec>"  << endl;
    cout << "<ROM path>: path to ROM"                    << endl;
    cout << "<instructions per sec>: defaults to 700"    << endl;
    cout                                                 << endl;
}

int readROMFile(char* path, vector<char> & buffer)
{
    ifstream ROMfile(path, ios::binary | ios::ate);
    if(ROMfile.fail())
        return 1;

    streamsize size = ROMfile.tellg();
    ROMfile.seekg(0, ios::beg);

    buffer = vector<char>(size);
    if (!ROMfile.read(buffer.data(), size))
        return 1;

    return 0;
}

double getTimeMs()
{
    return ((double)SDL_GetPerformanceCounter() / SDL_GetPerformanceFrequency()) * 1000.0;
}