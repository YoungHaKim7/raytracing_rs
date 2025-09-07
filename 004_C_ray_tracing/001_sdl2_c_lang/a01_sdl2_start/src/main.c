#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

#define WIDTH 900
#define HEIGHT 600

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Raytracing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

    SDL_Delay(5000);
    SDL_Quit();
    return 0;
}
