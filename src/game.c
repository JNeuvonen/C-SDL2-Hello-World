#include "game.h"
#include "levels.h"
#include <stdio.h>
#include "constants.h"
#include <stdbool.h>

void initialize_game(struct Game *game, SDL_Window *window, SDL_Renderer *renderer)
{
    // STATE
    game->state.level_loaded = 0;
    game->state.start = 1;
    game->state.game = 0;
    game->state.finish = 0;

    // SESSION
    game->session.curr_level = 1;

    // SDL_UTIL
    game->sdl_util.window = window;
    game->sdl_util.renderer = renderer;
    game->ux_util.menu_highlight_blink = 10;
}

void load_textures_handler(struct Game *game)
{
    int level_load_status;
    switch (game->session.curr_level)
    {
    case 1:
        level_load_status = load_first_level(game);

    case 2:
        break;
    }

    if (!level_load_status)
    {
        exit(EXIT_FAILURE);
    }

    game->state.level_loaded = 1;
}

void start_screen_tick(struct Game *game)
{
}

void gameplay_tick(struct Game *game)
{
}

void finish_screen_tick(struct Game *game)
{
}

void draw_text(struct Game *game,
               SDL_Color color, char *text,
               struct Coords coords, bool cntr_vertcl, bool cntr_hrzntl, bool h_font)
{
    SDL_Renderer *renderer = game->sdl_util.renderer;

    // paragraph or header
    TTF_Font *font = h_font ? game->sdl_util.h_font : game->sdl_util.p_font;

    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    int text_width = surface->w;
    int text_height = surface->h;

    SDL_FreeSurface(surface);

    SDL_Rect dstrect = {coords.x, coords.y, text_width, text_height};

    if (cntr_vertcl)
    {
        dstrect.y = WINDOW_H_HALF - text_height / 2;
    }

    if (cntr_hrzntl)
    {
        dstrect.x = WINDOW_W_HALF - text_width / 2;
    }

    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_DestroyTexture(texture);
}

void tick(struct Game *game)
{
    SDL_RenderClear(game->sdl_util.renderer);
    SDL_Color color = {156, 14, 38, 255};

    draw_text(game, color, "Minigolf THING", (struct Coords){.x = 0, .y = 0}, false, true, true);

    draw_text(game, color, "PLAY", (struct Coords){.x = 30, .y = 80}, false, false, false);

    if (game->state.level_loaded == 0 && game->state.game == 0)
    {
        load_textures_handler(game);
    }
    else if (game->state.start == 1)
    {
        start_screen_tick(game);
    }
    else if (game->state.game == 1)
    {
        gameplay_tick(game);
    }
    else if (game->state.finish == 1)
    {
        finish_screen_tick(game);
    }
    SDL_RenderPresent(game->sdl_util.renderer);
}

void event_loop_handler(SDL_bool *done, struct Game *game)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            *done = SDL_TRUE;
        }
        else if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
                break;
            case SDLK_DOWN:
                break;
            case SDLK_LEFT:
                break;
            case SDLK_RIGHT:
                break;
            case SDLK_a:
                break;
            case SDLK_b:
                break;
            }
        }
    }
}

void game_loop(struct Game *game)
{
    SDL_bool *done = SDL_FALSE;
    Uint32 frameStart;

    int frameTime;
    const int frameDelay = 1000 / 60;

    while (!done)
    {

        frameStart = SDL_GetTicks();

        event_loop_handler(done, game);
        tick(game);

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
}
