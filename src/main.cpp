#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "RenderWindow.h"

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL INIT HAS FAILED: " << SDL_GetError() << std::endl;
    }

    if(!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "SDL IMG INIT HAS FAILED: " <<SDL_GetError() << std::endl;
    }
    RenderWindow window("GAME v1.0", 1280, 720);

    return 0;
}