#include "MenuScene.h"
#include <cstdlib>
#include <SDL3/SDL_video.h>

MenuScene::MenuScene(SDL_Renderer* renderer){
    anim = IMG_LoadAnimation("../../assets/media/Yippiii.gif");
    if (!anim) {
        SDL_Log("Failed to load animation: %s", SDL_GetError());
        return;
    }
    anim_w = anim->w;
    anim_h = anim->h;
    SDL_Log("Animation loaded successfully: %d frames", anim->count);
    textures = (SDL_Texture **)SDL_calloc(anim->count, sizeof(*textures));
    int j;
    for (j = 0; j < anim->count; ++j) {
        textures[j] = SDL_CreateTextureFromSurface(renderer, anim->frames[j]);
    }
    current_frame = 0;
}

MenuScene::~MenuScene(){
    if (anim) {
        IMG_FreeAnimation(anim);
    }
    if (textures) {
        for(int i = 0; i<anim->count;i++){
            SDL_DestroyTexture(textures[i]);
        }
        
    }
}

void MenuScene::Render(SDL_Renderer& renderer){
    SDL_RenderTexture(&renderer, textures[current_frame],NULL,NULL);
    SDL_RenderPresent(&renderer);
    if (anim->delays[current_frame]) {
        delay = anim->delays[current_frame];
    } else {
        delay = 100;
    }
    SDL_Delay(delay);

    current_frame = (current_frame + 1) % anim->count;

}