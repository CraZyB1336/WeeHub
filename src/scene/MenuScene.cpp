#include "MenuScene.h"
#include <iostream>


MenuScene::MenuScene(SDL_Renderer* renderer)
{
    anim = IMG_LoadAnimation("../../assets/media/Yippiii.gif");
    if (!anim) {
        std::cerr << "GIF load failed: " << IMG_GetError() << std::endl;
        return;
    }

    textures.resize(anim->count);
    for (int i = 0; i < anim->count; i++) {
        textures[i] = SDL_CreateTextureFromSurface(renderer, anim->frames[i]);
    }

    frame = 0;
    nextFrameTime = SDL_GetTicks() + anim->delays[0];
}

MenuScene::~MenuScene()
{
    for (auto tex : textures)
        SDL_DestroyTexture(tex);

    if (anim) IMG_FreeAnimation(anim);
}

void MenuScene::Update(int deltaTime){

}

void MenuScene::Render(SDL_Renderer* renderer)
{
    Uint64 now = SDL_GetTicks();
    if (now >= nextFrameTime) {
        frame = (frame + 1) % anim->count;
        nextFrameTime = now + anim->delays[frame];
    }

    SDL_RenderTexture(renderer, textures[frame], nullptr, nullptr);
}
