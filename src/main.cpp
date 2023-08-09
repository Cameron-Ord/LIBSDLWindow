#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "RenderWindow.h"

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL INIT HAS FAILED: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "SDL IMG INIT HAS FAILED: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }



    {
        RenderWindow window("GAME v1.0", 1280, 720);
        SDL_Texture* grassTexture = window.loadTexture("/home/cameron/Documents/SDL2/res/gfx/ground_grass_1.png");
        bool gameRunning = true;
        SDL_Event event;

        while (gameRunning)
        {
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    gameRunning = false;
                }
            }
            window.clear();
            window.render(grassTexture);
            window.display();
        }
    } // The window object goes out of scope here and will be properly destroyed

    SDL_Quit();

    return 0;
}