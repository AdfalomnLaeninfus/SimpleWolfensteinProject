#ifndef _WOLFSTEIN_H_
#define _WOLFSTEIN_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    #include <SDL2/SDL.h>
    
    #include <vec2.h>
    #include <app.h>
    #include <utils.h>
    
    #include <entity.h>
    #include <player.h>

    #define WINDOW_TITLE        "Wolfenstein Project"
    #define MIN_WINDOW_WIDTH    800
    #define MIN_WINDOW_HEIGHT   600

    #define PI              3.1415926535
    #define PI_TIMES_TWO    6.2831853071
    #define PI_DIV_TWO      1.5707963267
    #define PI_DIV_180      0.0174532925

    #define MAP_SIZE_WIDTH  8
    #define MAP_SIZE_HEIGHT 8
    #define MAP_SIZE        64

    #define WALL_WIDTH      64
    #define WALL_HEIGHT     64

    #define PLAYER_VELOCITY 10

#endif
