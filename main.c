#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(WIN32)
    #define SDL_MAIN_HANDLED
#endif
#include <SDL2/SDL.h>

SDL_Event event;
SDL_Window *window;
SDL_Renderer *renderer;

int running = 1;

void handled_events(SDL_Event *event);

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Wolfstein", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    SDL_SetWindowMinimumSize(window, 800, 600);

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            handled_events(&event);
        }
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}

void handled_events(SDL_Event *event)
{
    switch (event->type)
    {
        case SDL_QUIT:
            running = !running;
            break;
    }
}