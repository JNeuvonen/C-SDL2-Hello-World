#ifndef COMMON_H
#define COMMON_H
#include <stdbool.h>
struct Coords
{
    int x;
    int y;
};

struct TileRect
{
    struct Coords start;
    int width;
    int height;
    bool horizontal;
};

int guardWindowSize(int rectWidth, int rectHeight);

struct TileRect get_tile_rect(int length, bool horizontal);

#endif
