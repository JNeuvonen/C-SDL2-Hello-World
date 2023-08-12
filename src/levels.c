#include "constants.h"
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

static void addTilesToLevel(struct TileRectVector *array, int tiles, bool horizontal, int startX, int startY, int idx)
{
    struct TileRect tileRect = get_tile_rect(tiles, horizontal);
    tileRect.start = (struct Coords){startX, startY};
    addToVec(array, tileRect);
};

static struct TileRectVector *first_level_tiles()
{

    struct TileRectVector *tilesVector;
    initTileVector(tilesVector);

    // Map boundaries
    addTilesToLevel(tilesVector, 1000, true, 0, LEVEL_PADDING, 0);
    addTilesToLevel(tilesVector, 1000, false, 0, LEVEL_PADDING, 1);
    addTilesToLevel(tilesVector, 1000, false, WINDOW_WIDTH - TILE_SIZE, LEVEL_PADDING, 2);
    addTilesToLevel(tilesVector, 1000, true, 0, WINDOW_HEIGHT - TILE_SIZE - LEVEL_PADDING, 3);

    // Level walls
    addTilesToLevel(tilesVector, 10, true, 150, 150, 4);
    addTilesToLevel(tilesVector, 10, false, 150, 150, 5);

    return tilesVector;
}

struct TileRectVector *get_tiles(int level)
{
    struct TileRectVector *tiles;
    switch (level)
    {
    case 1:
        tiles = first_level_tiles();
    }

    return tiles;
}