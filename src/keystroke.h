#ifndef KEYSTROKE_H
#define KEYSTROKE_H

#include "game.h"
#include <SDL2/SDL.h>

void handle_arrow_key(struct Game *game, SDL_KeyCode keycode);
void handle_enter_key(struct Game *game);

#endif
