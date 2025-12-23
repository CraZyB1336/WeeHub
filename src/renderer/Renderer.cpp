#include "Renderer.h"

Renderer::Renderer() 
{
}

Renderer::~Renderer(){
}

void Renderer::DrawGif(SDL_Renderer* renderer, const std::vector<std::unique_ptr<Gif>> &gifs){
    int time;
    for (const auto& g : gifs){
        time = SDL_GetTicks();
        if (g->delayTime < time){
            g->currentFrame = (g->currentFrame+1)%g->anim->count;
            SDL_RenderTexture(renderer, g->textures[g->currentFrame],NULL,&g->destRect);
            g->delayTime = time + g->anim->delays[g->currentFrame];
        }
        SDL_RenderTexture(renderer, g->textures[g->currentFrame],NULL,&g->destRect);
    }
}

std::unique_ptr<Gif> Renderer::LoadGIF(const char* filepath, SDL_Renderer* renderer,float x, float y, float width, float height){
    IMG_Animation* anim = IMG_LoadAnimation(filepath);
    if (!anim){
        SDL_Log("Failed to load animation: %s", SDL_GetError());
        return NULL;
    }
    SDL_Texture** textures = (SDL_Texture **) SDL_calloc(anim->count, sizeof(*textures));
    for (int i = 0; i < anim->count; ++i){
        textures[i] = SDL_CreateTextureFromSurface(renderer, anim->frames[i]);
    }
    SDL_FRect rect = {x,y,width,height};
    return std::make_unique<Gif>(anim,textures,0,rect);
}
