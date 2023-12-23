#if defined(_WIN32) || defined(_win32)
    #define SDL_MAIN_HANDLED
#endif

#include <wolfstein.h>

typedef struct app {
    SDL_Event event;
    SDL_Window *window;
    SDL_Renderer *renderer;

    bool quit;
} App;

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    App app;

    app.quit = false;

    app.window = SDL_CreateWindow(
        WINDOW_TITLE,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        MIN_WINDOW_WIDTH, MIN_WINDOW_HEIGHT, SDL_WINDOW_SHOWN
    );

    app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_SOFTWARE);

    while (app.quit) {
        while (SDL_PollEvent(&app.event)) {
            ;
        }
    }

    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    SDL_Quit();

    return 0;
}