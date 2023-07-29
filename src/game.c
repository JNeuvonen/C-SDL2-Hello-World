#include "game.h"
#include "levels.h"
#include <stdio.h>
#include "constants.h"
#include <stdbool.h>

void initialize_game(struct Game *game, SDL_Window *window, SDL_Renderer *renderer)
{
    // STATE
    game->state.level_loaded = false;
    game->mode = START_SCREEN;

    // SESSION
    game->session.curr_level = 1;
    game->session.start_menu_selected_item = 0;

    // SDL_UTIL
    game->sdl_util.window = window;
    game->sdl_util.renderer = renderer;
    game->ux_util.menu_highlight_blink = 10;

    SDL_SetRenderDrawColor(game->sdl_util.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
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

static void draw_start_screen_menu(struct Game *game)
{
    draw_text(game, TITLE_COLOR, "PLAY", (struct Coords){.x = 65, .y = 80}, false, false, false);
    draw_text(game, TITLE_COLOR, "OPTIONS", (struct Coords){.x = 65, .y = 80 + 1 * MENU_ITM_HRZTNL_SPCING}, false, false, false);
    draw_text(game, TITLE_COLOR, "QUIT", (struct Coords){.x = 65, .y = 80 + 2 * MENU_ITM_HRZTNL_SPCING}, false, false, false);
}

static void draw_menu_triangle(struct Game *game)
{
    int size = 14;
    int x = 50;
    int y = 90 + game->session.start_menu_selected_item * MENU_ITM_HRZTNL_SPCING;

    SDL_Point points[4] = {
        {x, y},
        {x, y + size},
        {x + size / 2, y + size / 2},
        {x, y}};

    SDL_SetRenderDrawColor(game->sdl_util.renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLines(game->sdl_util.renderer, points, 4);

    SDL_SetRenderDrawColor(game->sdl_util.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

void start_screen_tick(struct Game *game)
{

    SDL_Color color = {156, 14, 38, 255};

    draw_text(game, color, "JUMPALOT", (struct Coords){.x = 0, .y = 0}, false, true, true);

    draw_start_screen_menu(game);
    draw_menu_triangle(game);
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

    dstrect.y = cntr_vertcl ? WINDOW_H_HALF - text_height / 2 : coords.y;
    dstrect.x = cntr_hrzntl ? WINDOW_W_HALF - text_width / 2 : coords.x;

    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_DestroyTexture(texture);
}

void tick(struct Game *game)
{

    if (game->state.level_loaded == false && game->mode == GAME)
        load_textures_handler(game);
    else if (game->mode == START_SCREEN)
        start_screen_tick(game);
    else if (game->mode == GAME)
        gameplay_tick(game);
    else if (game->mode == FINISH_SCREEN)
        finish_screen_tick(game);
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
            case SDLK_DOWN:
            case SDLK_LEFT:
            case SDLK_RIGHT:
                handle_arrow_key(game, event.key.keysym.sym);
                break;

            case SDLK_RETURN:
            case SDLK_KP_ENTER:
                handle_enter_key(game);
                break;
            }
        }
    }
}

void game_loop(struct Game *game)
{
    SDL_bool done = SDL_FALSE;
    Uint32 frameStart;

    int frameTime;
    const int frameDelay = 1000 / 60;

    while (!done)
    {
        SDL_RenderClear(game->sdl_util.renderer);
        Uint32 frameStart = SDL_GetTicks();

        event_loop_handler(&done, game);
        tick(game);

        int frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);

        SDL_RenderPresent(game->sdl_util.renderer);
    }
}
