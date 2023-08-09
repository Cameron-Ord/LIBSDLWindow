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



SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
    SDL_Texture* texture = NULL;
    std::cout << "Loading texture from path: " << p_filePath << std::endl;

    texture = IMG_LoadTexture(renderer, p_filePath);
    std::cout << "assigning texture: " << texture << std::endl;

    if(texture == NULL)
    {
        std::cout << "Failed to load texture: " << IMG_GetError() << std::endl;
    }
    return texture;
}

void RenderWindow::cleanUp()
{
    if (window != NULL)
    {
        SDL_DestroyWindow(window);
        window = NULL; // Set to NULL after destruction to prevent double deletion
    }
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);

}

void RenderWindow::render(SDL_Texture* p_tex)
{
    SDL_RenderCopy(renderer, p_tex, NULL, NULL);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}