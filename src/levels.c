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

static void addTilesToLevel(struct TileRect *array, int tiles, bool horizontal, int startX, int startY, int idx)
{
    struct TileRect tileRect = get_tile_rect(tiles, horizontal);
    tileRect.start = (struct Coords){startX, startY};
    array[idx] = tileRect;
};

static struct TileRect *first_level_tiles()
{

    const int ROWS = 100;

    // Map boundaries
    struct TileRect *array = malloc(ROWS * sizeof(struct Coords *));
    addTilesToLevel(array, 1000, true, 0, LEVEL_PADDING, 0);
    addTilesToLevel(array, 1000, false, 0, LEVEL_PADDING, 1);
    addTilesToLevel(array, 1000, false, WINDOW_WIDTH - TILE_SIZE, LEVEL_PADDING, 2);
    addTilesToLevel(array, 1000, true, 0, WINDOW_HEIGHT - TILE_SIZE - LEVEL_PADDING, 3);

    // Level walls
    addTilesToLevel(array, 10, true, 32, 32, 4);
    addTilesToLevel(array, 10, false, 32 + 10 * TILE_SIZE, 32, 5);

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