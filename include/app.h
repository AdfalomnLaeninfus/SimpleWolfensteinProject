#ifndef _APP_H_
#define _APP_H_

#include <vec2.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

typedef Vec2 WindowRatio;

typedef struct window_size {
    int width;
    int height;
} WindowSize;

typedef struct app {
    SDL_Event event;
    SDL_Window *window;
    SDL_Renderer *renderer;
    WindowSize window_size;
    WindowRatio window_ratio;

    bool quit;
    unsigned int *keyboardKeys;
} App;

#endif
