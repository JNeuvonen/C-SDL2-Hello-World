#include "keystroke.h"
#include "game.h"
#include <SDL2/SDL.h>
#include "constants.h"

static handle_start_screen_arrow_key(struct Game *game, SDL_KeyCode keycode)
{
    int curr_value = game->session.start_menu_selected_item;
    if (keycode == SDLK_UP)
    {
        game->session.start_menu_selected_item = curr_value > 0 ? curr_value - 1 : curr_value;
    }
    else if (keycode == SDLK_DOWN)
    {
        game->session.start_menu_selected_item = curr_value < START_SCREEN_MENU_ITEM_COUNT ? curr_value + 1 : curr_value;
    }
}

static handle_game_screen_arrow_key(struct Game *game, SDL_KeyCode keycode)
{
}

static handle_finish_screen_arrow_key(struct Game *game, SDL_KeyCode keycode)
{
}

void handle_arrow_key(struct Game *game, SDL_KeyCode keycode)
{

    if (game->state.start)
    {
        handle_start_screen_arrow_key(game, keycode);
    }

    else if (game->state.game)
    {
        handle_game_screen_arrow_key(game, keycode);
    }

    else if (game->state.finish)
    {

        handle_finish_screen_arrow_key(game, keycode);
    }
}
