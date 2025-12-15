#pragma once

#include "Scene.h"
#include "../renderer/Renderer.h"
#include <SDL3_image/SDL_image.h>

class MenuScene : public Scene {
    public:
        MenuScene(SDL_Renderer* renderer);
        ~MenuScene();
        // void OnEnter() override;
        // void OnExit() override;
        void Update(int deltaTime) override;
        void Render(SDL_Renderer& renderer) override;
        // void HandleInput(const Input& input) override;
    
    private:
        // std::unique_ptr<ChannelGrid> channelGrid;
        // std::unique_ptr<Cursor> cursor;
        // Camera camera;
        SDL_Texture* textures;
        IMG_Animation* anim;
        int frame;
        int nextFrameTime;
};