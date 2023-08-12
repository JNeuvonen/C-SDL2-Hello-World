#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SDL.h>
#include "game.h"

#define WINDOW_WIDTH 800
#define LEVEL_PADDING 50
#define WINDOW_HEIGHT 608
#define MENU_ITM_HRZTNL_SPCING 40
#define START_SCREEN_MENU_ITEM_COUNT 2

#define WINDOW_W_HALF (WINDOW_WIDTH / 2)
#define WINDOW_H_HALF (WINDOW_HEIGHT / 2)

extern const SDL_Color TITLE_COLOR;
extern const SDL_Color HEADER_COLOR;

struct TileRectVector
{
    int len;
    struct TileRect *items;
    int idx;
};

void addToVec(struct TileRectVector *arr, struct TileRect new_item);

void initTileVector(struct TileRectVector *arr);

#endif
