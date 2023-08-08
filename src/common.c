#include "common.h"
#include "constants.h"
#include "game.h"

int guardWindowSize(int rectWidth, int maxWidth)
{
    return rectWidth > maxWidth ? maxWidth : rectWidth;
}

struct TileRect get_tile_rect(int length, bool horizontal)
{

    struct TileRect ret;

    if (horizontal)
    {

        ret.width = guardWindowSize(TILE_SIZE * length, WINDOW_WIDTH);
        ret.height = TILE_SIZE;
    }
    else
    {
        ret.width = TILE_SIZE;
        ret.height = guardWindowSize(TILE_SIZE * length, WINDOW_HEIGHT - LEVEL_PADDING * 2);
    }

    ret.horizontal = horizontal;

    return ret;
};
