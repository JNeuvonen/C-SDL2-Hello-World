#include "constants.h"

const SDL_Color TITLE_COLOR = {156, 14, 38, 255};
const SDL_Color HEADER_COLOR = {156, 14, 38, 255};

void addToArr(struct DynamicArray *arr, int new_item)
{
    if (arr->idx == arr->len)
    {
        arr->len *= 2;

        int *new_arr = (int *)realloc(arr->items, arr->len * sizeof(int));
        if (new_arr == NULL)
        {
            return;
        }
        arr->items = new_arr;
    }

    arr->items[arr->idx] = new_item;
    arr->idx++;
}
