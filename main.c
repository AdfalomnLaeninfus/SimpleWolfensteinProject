#if defined(_WIN32) || defined(_win32)
    #include <windows.h>    
#endif

#include <wolfenstein.h>
#include <stdint.h>

const int map[MAP_SIZE] = {
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1
};

int main(int argc, char *argv[])
{
    App app;
    EntityInstance_t player;

    Vec2 keysPressed = { 0.0f, 0.0f };
    Vec2 windowCenter = { 0.0f, 0.0f };

    player.atributes.hasPlayable = true;
    player.transform.position.x = player.transform.position.y = 32 + MAP_SIZE  * 2;
    player.transform.rotation.x = player.transform.rotation.y = 0.0f;

    SDL_Init( SDL_INIT_VIDEO );

    app.window = SDL_CreateWindow(
        WINDOW_TITLE,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        MIN_WINDOW_WIDTH, MIN_WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    SDL_SetWindowMinimumSize(app.window, MIN_WINDOW_WIDTH, MIN_WINDOW_HEIGHT);

    app.renderer = SDL_CreateRenderer( app.window, -1, SDL_RENDERER_SOFTWARE );
    SDL_GetWindowSize( app.window, &app.window_size.width, &app.window_size.height );

    app.keyboardKeys = (unsigned char *) SDL_GetKeyboardState(NULL);

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
                case SDL_MOUSEMOTION:
                    int mouseX, mouseY;
                    float mouseSensibility = 0.02f;

                    SDL_GetRelativeMouseState( &mouseX, &mouseY );

                    set_entity_rotation( &player.transform, (Vec2)
                        {
                            player.transform.rotation.x - sinf( mouseSensibility * -mouseX ),
                            player.transform.rotation.y + cosf( mouseSensibility * mouseY )
                        }
                    );

                    break;
            }
        }

        if ( app.keyboardKeys[SDL_SCANCODE_W] ) { keysPressed.y += 1; }
        if ( app.keyboardKeys[SDL_SCANCODE_D] ) { keysPressed.x += 1; }
        if ( app.keyboardKeys[SDL_SCANCODE_S] ) { keysPressed.y -= 1; }
        if ( app.keyboardKeys[SDL_SCANCODE_A] ) { keysPressed.x -= 1; }

        float pPosX, pPosY, pRotX, pRotY;

        pPosX = player.transform.position.x;
        pPosY = player.transform.position.y;
        pRotX = player.transform.rotation.x;
        pRotY = player.transform.rotation.y;


        if ( keysPressed.y != 0.0f )
        {
            set_entity_place( &player.transform, (Vec2)
                {
                    pPosX + (sinf(pRotX) * (PLAYER_VELOCITY * keysPressed.y)),
                    pPosY - (cosf(pRotX) * (PLAYER_VELOCITY * keysPressed.y))
                }
            );
        }

        keysPressed.x = keysPressed.y = 0;

        windowCenter = App_GetCenterWindow( app.window );
        SDL_WarpMouseInWindow( app.window, windowCenter.x, windowCenter.y );

        draw_map( map, &app );
        draw_rect( &app, player.transform.position.x, player.transform.position.y, 12, 12);

        SDL_SetRenderDrawColor( app.renderer, 255, 0, 255, 255 );
        SDL_RenderDrawLine(
            app.renderer,

            pPosX + 5,
            pPosY + 5,

            pPosX + (sinf(pRotX) * 25),
            pPosY - (cosf(pRotX) * 25)
        );

        SDL_RenderPresent( app.renderer );
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    SDL_Quit();
}

#if defined(_WIN32) || defined(_win32)
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    return main(__argc, __argv);
}
#endif