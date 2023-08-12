#include "constants.h"
#include "game.h"

const SDL_Color TITLE_COLOR = {156, 14, 38, 255};
const SDL_Color HEADER_COLOR = {156, 14, 38, 255};

void addToVec(struct TileRectVector *arr, struct TileRect new_item)
{
    if (arr->idx == arr->len)
    {
        arr->len *= 2;

        int *new_arr = (int *)realloc(arr->items, arr->len * sizeof(new_item));
        if (new_arr == NULL)
        {
            return;
        }
        arr->items = new_arr;
    }

    arr->items[arr->idx] = new_item;
    arr->idx++;
}

void initTileVector(struct TileRectVector *arr)
{
    int init_capacity = 100;
    arr->len = 0;
    arr->idx = 0;
    arr->items = (struct TileRect *)malloc(init_capacity * sizeof(struct TileRect));
}
