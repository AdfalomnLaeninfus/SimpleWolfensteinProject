#if defined(_WIN32) || defined(_win32)
    #define SDL_MAIN_HANDLED
#endif

#include <wolfenstein.h>

SDL_Rect p;

int main(int argc, char *argv[])
{
    App app;
    EntityInstance p;

    p.atributes.hasPlayable = true;
    p.transform.position.x = p.transform.position.y = 32 + MAP_SIZE  * 2 ;
    p.transform.angle = p.transform.rotation.x = p.transform.rotation.y = 0.0f;

    const int map[MAP_SIZE] = {
        1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 1, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1
    };

    SDL_Init( SDL_INIT_VIDEO );

    app.window = SDL_CreateWindow(
        WINDOW_TITLE,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        MIN_WINDOW_WIDTH, MIN_WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    app.renderer = SDL_CreateRenderer( app.window, -1, SDL_RENDERER_SOFTWARE );

    app.quit = false;
    while ( !app.quit )
    {
        SDL_SetRenderDrawColor( app.renderer, 0, 0, 0, 255 );
        SDL_RenderClear( app.renderer );

        while ( SDL_PollEvent( &app.event ) )
        {
            switch (app.event.type)
            {
                case SDL_QUIT: app.quit = true;
                case SDL_KEYDOWN:
                    switch (app.event.key.keysym.sym) {
                        case SDLK_w:
                            set_entity_place( &p, (Vec2) { p.transform.position.x, p.transform.position.y - PLAYER_VELOCITY } );
                            break;
                        case SDLK_s:
                            set_entity_place( &p, (Vec2) { p.transform.position.x, p.transform.position.y + PLAYER_VELOCITY } );
                            break;
                        case SDLK_a:
                            set_entity_place( &p, (Vec2) { p.transform.position.x - PLAYER_VELOCITY, p.transform.position.y } );
                            break;
                        case SDLK_d:
                            set_entity_place( &p, (Vec2) { p.transform.position.x + PLAYER_VELOCITY, p.transform.position.y } );
                            break;
                    };
            }
        }

        draw_map( map, &app );
        draw_rect( &app, p.transform.position.x, p.transform.position.y, 12, 12);
        SDL_RenderPresent( app.renderer );

        SDL_Delay(16);
    }

    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    SDL_Quit();
}
