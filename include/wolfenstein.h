#ifndef _WOLFSTEIN_H_
#define _WOLFSTEIN_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    #if defined(_WIN32) || defined(_win32)
        #define SDL_HANDLED_MAIN
    #endif
    #include <SDL2/SDL.h>
    
    #include <vec2.h>
    #include <app.h>
    #include <utils.h>
    
    #include <entity.h>
    #include <player.h>

    #define WINDOW_TITLE        "Wolfenstein Project"
    #define MIN_WINDOW_WIDTH    800
    #define MIN_WINDOW_HEIGHT   600

#endif
