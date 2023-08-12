
#ifndef LEVELS_H
#define LEVELS_H
#include "common.h"
#include "game.h"
#include <SDL2/SDL.h>

int load_first_level(struct Game *game);

struct TileRectVector *get_tiles(int level);

#endif
