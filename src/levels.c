#include "common.h"
#include "levels.h"
#include <SDL2_image/SDL_image.h>

int load_texture(SDL_Renderer *renderer, const char *filename, SDL_Texture **out_texture)
{
    *out_texture = IMG_LoadTexture(renderer, filename);
    if (!*out_texture)
    {
        fprintf(stderr, "Failed to load texture: %s. SDL_image Error: %s\n", filename, IMG_GetError());
        return 0;
    }

    return 1;
}

int load_first_level(struct Game *game)
{
    if (!load_texture(game->sdl_util.renderer, "assets/stonewall_grayscale.png", &(game->level_1_assets.surface)))
        return 0;
    if (!load_texture(game->sdl_util.renderer, "assets/stonewall_grayscale.png", &(game->level_1_assets.test)))
        return 0;

    game->session.tiles = get_tiles(game->session.curr_level);

    return 1;
};

static struct TileRect *first_level_tiles()
{

    const int ROWS = 100;

    struct TileRect *array = malloc(ROWS * sizeof(struct Coords *));
    struct TileRect rectDim1 = get_tile_rect(1000, true);
    rectDim1.start = (struct Coords){0, 0};
    struct TileRect rectDim2 = get_tile_rect(1000, false);
    rectDim2.start = (struct Coords){WINDOW_WIDTH - TILE_SIZE, 0};
    struct TileRect rectDim3 = get_tile_rect(1000, true);
    rectDim3.start = (struct Coords){0, WINDOW_HEIGHT - TILE_SIZE};
    struct TileRect rectDim4 = get_tile_rect(1000, false);
    rectDim4.start = (struct Coords){0, 0};

    array[0] = rectDim1;
    array[1] = rectDim2;
    array[2] = rectDim3;
    array[3] = rectDim4;

    return array;
}

struct TileRect *get_tiles(int level)
{

    struct TileRect *tiles;

    switch (level)
    {
    case 1:
        tiles = first_level_tiles();
    }

    return tiles;
}