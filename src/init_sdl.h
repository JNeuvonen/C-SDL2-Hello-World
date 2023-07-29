#ifndef INIT_SDL_H
#define INIT_SDL_H

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "game.h"

SDL_Window *init_window(const char *project_name, int width, int height);
SDL_Renderer *init_renderer(SDL_Window *window);
void init_TTF(struct Game *game);

#endif