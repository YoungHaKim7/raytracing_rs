#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

#define WIDTH 900
#define HEIGHT 600
#define COLOR_WHITE 0xffffffff

struct Circle {
    double x;
    double y;
    double radius;
}; // <-- missing semicolon

void FillCircle(SDL_Surface* surface, struct Circle circle, Uint32 color)
{
    double radius_squared = circle.radius * circle.radius;
    for (double x = circle.x - circle.radius; x < circle.x + circle.radius; x++)
    {
        for (double y = circle.y - circle.radius; y <= circle.y + circle.radius; y++)
        {
            double distance_squared = (x - circle.x) * (x - circle.x) + (y - circle.y) * (y - circle.y);
            if (distance_squared < radius_squared)
            {
                SDL_Rect pixel = { (int)x, (int)y, 1, 1 };
                SDL_FillRect(surface, &pixel, color); // pass pointer, only 3 args
            }
        }
    }
}

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Raytracing",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        0
    );

    if (!window) {
        fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Surface* surface = SDL_GetWindowSurface(window);

    struct Circle circle = {200, 200, 80};
    FillCircle(surface, circle, COLOR_WHITE);

    SDL_UpdateWindowSurface(window);

    SDL_Delay(5000);
    SDL_Quit();
    return 0;
}
