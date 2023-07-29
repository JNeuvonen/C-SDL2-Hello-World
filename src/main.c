#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "game.h"
#include "init_sdl.h"
#include "constants.h"

int main(int argc, char *argv[])
{

    const char *PROJECT_NAME = "MINIGOLF THING";

    SDL_Window *window = init_window(PROJECT_NAME, WINDOW_WIDTH, WINDOW_HEIGHT);
    SDL_Renderer *renderer = init_renderer(window);
    SDL_bool done = SDL_FALSE;

    struct Game *game = malloc(sizeof(struct Game));
    initialize_game(game, window, renderer);
    init_TTF(game);

    SDL_Texture *texture = IMG_LoadTexture(renderer, "assets/stonewall_grayscale.png");

    game_loop(game);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
