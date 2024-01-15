#ifndef _APP_H_
#define _APP_H_

#include <vec2.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

typedef Vec2f WindowRatio;

typedef Vec2i WindowSize;

typedef struct app {
    SDL_Event event;
    SDL_Window *window;
    SDL_Renderer *renderer;
    WindowSize window_size;
    WindowRatio window_ratio;

    bool quit;
    unsigned char *keyboardKeys;
} App;

extern Vec2f App_GetCenterWindow( SDL_Window *window );

#endif
