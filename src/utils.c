#include <utils.h>

void draw_map( const int *map, App *app )
{
    int x, y, xo, yo;

    for ( y = 0; y < MAP_SIZE_HEIGHT; y++ )
    {
        for ( x = 0; x < MAP_SIZE_WIDTH; x++ )
        {
            if (map[y * MAP_SIZE_WIDTH + x] == 1) {
                SDL_SetRenderDrawColor( app->renderer, 255, 255, 255, 255 );
            } else {
                SDL_SetRenderDrawColor( app->renderer, 0, 0, 0, 255 );
            }

            xo = x * MAP_SIZE;
            yo = y * MAP_SIZE;

            SDL_Rect r = { xo + MAP_SIZE, yo + MAP_SIZE, WALL_WIDTH, WALL_HEIGHT };
            SDL_RenderFillRect( app->renderer, &r );
        }
    }
}

void draw_rect( App *app, int x, int y, int w, int h )
{
    SDL_Rect r = { x, y, w, h };
    SDL_SetRenderDrawColor( app->renderer, 255, 255, 255, 255 );
    SDL_RenderFillRect( app->renderer, &r );
}