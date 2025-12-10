#include "MenuScene.h"

MenuScene::MenuScene(){

}

void MenuScene::Render(SDL_Renderer& renderer){
    SDL_SetRenderDrawColor(&renderer, 50, 50, 50, 255);
    SDL_RenderClear(&renderer);
    SDL_SetRenderDrawColor(&renderer, 0, 255, 0, 255);
    SDL_FRect rect = {100, 100, 200, 100};
    SDL_RenderRect(&renderer, &rect);
    SDL_RenderPresent(&renderer);
}