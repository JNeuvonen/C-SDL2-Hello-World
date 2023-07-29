#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "init_sdl.h"

SDL_Window *init_window(const char *project_name, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return NULL;
    }

    SDL_Window *window = SDL_CreateWindow(project_name,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          width, height,
                                          0);

    if (!window)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
    }

    return window;
}

SDL_Renderer *init_renderer(SDL_Window *window)
{
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
    }

    return renderer;
}
void init_TTF(struct Game *game)
{
    TTF_Init();

    TTF_Font *p_font = TTF_OpenFont("/Library/Fonts/Arial Unicode.ttf", 24);
    TTF_Font *h_font = TTF_OpenFont("/Library/Fonts/Arial Unicode.ttf", 32);

    if (p_font == NULL || h_font == NULL)
    {
        printf("Failed to load font: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    game->sdl_util.p_font = p_font;
    game->sdl_util.h_font = h_font;
}