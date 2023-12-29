#include <app.h>

Vec2 App_GetCenterWindow( SDL_Window *window )
{
    int width, height;
    SDL_GetWindowSize( window, &width, &height );
    
    return (Vec2) { width * 0.5f, height * 0.5f };
}