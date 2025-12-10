#pragma once

#include "Scene.h"
#include "../renderer/Renderer.h"

class MenuScene : public Scene {
    public:
        MenuScene();

        // void OnEnter() override;
        // void OnExit() override;
        // void Update(float deltaTime) override;
        void Render(Renderer& renderer) override;
        // void HandleInput(const Input& input) override;
    
    private:
        // std::unique_ptr<ChannelGrid> channelGrid;
        // std::unique_ptr<Cursor> cursor;
        // Camera camera;
};