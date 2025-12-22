#pragma once

#include "Scene.h"
#include "../renderer/Renderer.h"
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL.h>
#include <memory>
#include <vector>

class MenuScene : public Scene {
    public:
        MenuScene(SDL_Renderer* renderer);
        ~MenuScene() override;
        // void OnEnter() override;
        // void OnExit() override;
        // void Update(int deltaTime) override;
        void Render(SDL_Renderer& renderer) override;
        // void HandleInput(const Input& input) override;
    
    private:
        // std::unique_ptr<ChannelGrid> channelGrid;
        // std::unique_ptr<Cursor> cursor;
        // Camera camera;
        IMG_Animation* anim = nullptr;
        IMG_Animation* anim2 = nullptr;
        SDL_Texture** textures2;
        int anim_w, anim_h;
        float frame_time = 0.0f;
        int current_frame = 0;
        int last_time = 0;
        int current_time = 0;
        SDL_Texture** textures;
        SDL_Renderer* renderer;
        int delay;
        SDL_FRect gif;
        SDL_FRect gif2;
        // int renderFlag;

        std::vector<std::unique_ptr<Gif>> gifs;
        std::unique_ptr<Renderer> egenRender;
};