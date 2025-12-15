#include "MenuScene.h"
#include <cstdlib>
#include <SDL3/SDL_video.h>

MenuScene::MenuScene(SDL_Renderer* renderer){
    anim = IMG_LoadAnimation("../assets/toothless-toothless-dragon.gif");
    if (!anim) {
        SDL_Log("Failed to load animation: %s", SDL_GetError());
        return;
    }
    anim_w = anim->w;
    anim_h = anim->h;
    SDL_Log("Animation loaded successfully: %d frames", anim->count);
    textures = (SDL_Texture **)SDL_calloc(anim->count, sizeof(*textures));
    int j,i;
    for (j = 0; j < anim->count; ++j) {
        textures[j] = SDL_CreateTextureFromSurface(renderer, anim->frames[j]);
    }
    current_frame = 0;


    const SDL_Color col[2] = {
        { 0x66, 0x66, 0x66, 0xff },
        { 0x99, 0x99, 0x99, 0xff }
    };
    rect.w, rect.h = 8;
    for (int y=0;y<anim_h; y+=8){
        for (int x = 0; x< anim_w;x+=8){
            i=(((x^y)>>3)&1);
            SDL_SetRenderDrawColor(renderer, col[i].r, col[i].g,col[i].b,col[i].a);
            rect.x = (float)x;
            rect.y = (float)y;
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

MenuScene::~MenuScene(){
    if (textures) {
        for(int i = 0; i<anim->count;i++){
            SDL_DestroyTexture(textures[i]);
        }
    }
    SDL_free(textures);
    if (anim) {
        IMG_FreeAnimation(anim);
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
