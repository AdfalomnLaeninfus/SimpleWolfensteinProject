#ifndef _UTILS_H_
#define _UTILS_H_

#include "app.h"

void draw_map( const int *map, App *app );
void draw_rect( App *app, int x, int y, int w, int h );

WindowRatio get_window_ratio( App *app );

#endif