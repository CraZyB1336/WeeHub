#include <SDL3/SDL.h>
#include <SDL3/SDL_ttf.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() == -1) {
        printf("TTF_Init Error: %s\n", TTF_GetError());
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("SDL3 Text Test",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       640, 480, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, 0);

    TTF_Font *font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf", 24);
    if (!font) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        return 1;
    }

    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderUTF8_Blended(font, "Hello SDL3!", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    SDL_Rect dstrect = { 50, 50, 300, 50 };

    int running = 1;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = 0;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, texture, NULL, &dstrect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
