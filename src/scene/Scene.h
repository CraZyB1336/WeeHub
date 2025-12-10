#pragma once

#include "../renderer/Renderer.h"

class Scene{
    public:
        virtual ~Scene() = default;

        // virtual void OnEnter() = 0;
        // virtual void OnExit() = 0;
        // virtual void Update(float deltaTime) = 0;
        virtual void Render(SDL_Renderer& renderer) = 0;
        // virtual void HandleInput(const Input& input) = 0;
};