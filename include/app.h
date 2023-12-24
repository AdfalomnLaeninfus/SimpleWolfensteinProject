#ifndef _APP_H_
#define _APP_H_

#include <wolfenstein.h>

typedef struct app {
    SDL_Event event;
    SDL_Window *window;
    SDL_Renderer *renderer;

    bool quit;
} App;

#endif