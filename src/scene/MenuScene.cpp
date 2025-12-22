#include "MenuScene.h"
#include <cstdlib>
#include <iostream>
#include <SDL3/SDL_video.h>

MenuScene::MenuScene(SDL_Renderer* renderer){
    egenRender = std::make_unique<Renderer>();
    gifs.push_back(egenRender->LoadGIF("../assets/spinningbee.gif",renderer,100,100,200,100));
    gifs.push_back(egenRender->LoadGIF("../assets/toothless-toothless-dragon.gif",renderer, 400,100,200,100));
    std::cout << "init ferdig"<<"\n";
    current_frame = 0;
}

MenuScene::~MenuScene(){
    // if (textures) {
    //     for(int i = 0; i<anim->count;i++){
    //         SDL_DestroyTexture(textures[i]);
    //     }
    // }
    // SDL_free(textures);
    // if (anim) {
    //     IMG_FreeAnimation(anim);
    // }
}

void MenuScene::Render(SDL_Renderer& renderer){
    SDL_RenderClear(&renderer);
    egenRender->DrawGif(&renderer, gifs);
    SDL_RenderPresent(&renderer);
}
