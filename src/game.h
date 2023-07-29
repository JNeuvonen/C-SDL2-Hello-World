#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "common.h"
#include <stdbool.h>
#include "constants.h"

struct State
{
    bool level_loaded;
    bool start;
    bool game;
    bool finish;
};

struct Session
{
    int curr_level;
};

struct SDL_util
{
    struct SDL_Window *window;
    struct SDL_Renderer *renderer;
    TTF_Font *h_font;
    TTF_Font *p_font;
};

struct UX_util
{
    int menu_highlight_blink;
};

struct Level1Assets
{
    SDL_Texture *felt;
    SDL_Texture *ball;
};

struct Game
{
    struct State state;
    struct Session session;
    struct SDL_util sdl_util;
    struct Level1Assets level_1_assets;
    struct UX_util ux_util;
};

void initialize_game(struct Game *game, struct SDL_Window *window, struct SDL_Renderer *renderer);

void game_loop(struct Game *game);

void load_textures_handler(struct Game *game);

void start_screen_tick(struct Game *game);

void gameplay_tick(struct Game *game);

void finish_screen_tick(struct Game *game);

void draw_text(struct Game *game, SDL_Color color, char *text, struct Coords coords, bool cntr_vertcl, bool cntr_hrzntl, bool h_font);

void event_loop_handler(SDL_bool *done, struct Game *game);

#endif
