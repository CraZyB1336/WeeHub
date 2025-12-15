#pragma once

#include "Scene.h"
#include "../renderer/Renderer.h"
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL.h>

class MenuScene : public Scene {
    public:
        MenuScene(SDL_Renderer* renderer);
        ~MenuScene() override;
        // void OnEnter() override;
        // void OnExit() override;
        // void Update(float deltaTime) override;
        void Render(SDL_Renderer& renderer) override;
        // void HandleInput(const Input& input) override;
    
    private:
        // std::unique_ptr<ChannelGrid> channelGrid;
        // std::unique_ptr<Cursor> cursor;
        // Camera camera;
        IMG_Animation* anim = nullptr;
        int anim_w, anim_h;
        float frame_time = 0.0f;
        int current_frame = 0;
        int last_time = 0;
        int current_time = 0;
        SDL_Texture** textures;
        SDL_Renderer* renderer;
        int delay;
};