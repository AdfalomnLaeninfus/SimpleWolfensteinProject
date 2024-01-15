#include <app.h>

Vec2f App_GetCenterWindow( SDL_Window *window )
{
    int width, height;
    SDL_GetWindowSize( window, &width, &height );
    
    return ( Vec2f ) { width * 0.5f, height * 0.5f };
}