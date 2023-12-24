#ifndef _APP_H_
#define _APP_H_

#include <wolfenstein.h>

typedef Vec2 WindowRatio;

typedef struct app {
    SDL_Event event;
    SDL_Window *window;
    SDL_Renderer *renderer;
    WindowRatio window_ratio;

    bool quit;
} App;

#endif