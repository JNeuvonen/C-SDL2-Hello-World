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
    if (!load_texture(game->sdl_util.renderer, "assets/stonewall_grayscale.png", &(game->level_1_assets.ball)))
        return 0;
    if (!load_texture(game->sdl_util.renderer, "assets/stonewall_grayscale.png", &(game->level_1_assets.felt)))
        return 0;

    return 1;
};
