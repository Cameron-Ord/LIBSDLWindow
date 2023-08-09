#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "RenderWindow.h"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

    if(window == NULL)
    {
        std::cout << "Window Failed to init: " << SDL_GetError() << std::endl;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}


void RenderWindow::cleanUp()
{
    if (window != NULL)
    {
        SDL_DestroyWindow(window);
        window = NULL; // Set to NULL after destruction to prevent double deletion
    }
}