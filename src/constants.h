#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SDL.h>

#define WINDOW_WIDTH 800
#define LEVEL_PADDING 50
#define WINDOW_HEIGHT 608
#define MENU_ITM_HRZTNL_SPCING 40
#define START_SCREEN_MENU_ITEM_COUNT 2

#define WINDOW_W_HALF (WINDOW_WIDTH / 2)
#define WINDOW_H_HALF (WINDOW_HEIGHT / 2)

extern const SDL_Color TITLE_COLOR;
extern const SDL_Color HEADER_COLOR;

struct DynamicArray
{
    int len;
    int *items;
    int idx;
};

void addToArr(struct DynamicArray *arr, int new_item);

#endif
