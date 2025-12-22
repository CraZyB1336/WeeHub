#pragma once

#include <SDL3/SDL.h>
#include "Renderer.h"
#include <SDL3_image/SDL_image.h>
#include <memory>
#include <iostream>
#include <SDL3/SDL_opengl.h>
#include <vector>

struct Gif{
    IMG_Animation* anim;
    SDL_Texture** textures;
    int currentFrame;
    SDL_FRect destRect;
    Uint64 delayTime;
};

class Renderer{
    public:
        Renderer();
        ~Renderer();
        std::unique_ptr<Gif> LoadGIF(const char* filepath, SDL_Renderer* renderer,float x, float y, float width, float height);
        void DrawGif(SDL_Renderer* renderer, const std::vector<std::unique_ptr<Gif>> &gifs);

    private:
        SDL_GLContext glContext;
        SDL_Window* window;
};

