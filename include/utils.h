#ifndef _UTILS_H_
#define _UTILS_H_

#include "app.h"

#ifndef PI
    #define PI              3.1415926535
#endif

#define PI_TIMES_TWO    6.2831853071
#define PI_DIV_TWO      1.5707963267
#define PI_DIV_180      0.0174532925

#define MAP_SIZE_WIDTH  8
#define MAP_SIZE_HEIGHT 8
#define MAP_SIZE        64

#define WALL_WIDTH      64
#define WALL_HEIGHT     64

#define PLAYER_VELOCITY .2

float toRadians( float degrees );

void draw_map( const int *map, App *app );
void draw_rect( App *app, int x, int y, int w, int h );

WindowRatio get_window_ratio( App *app );

#endif