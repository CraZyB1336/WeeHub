#pragma once

#include <memory>
#include "Scene.h"
#include "../renderer/Renderer.h"

class SceneManager{
    public:
        SceneManager(SDL_Renderer* renderer);
        ~SceneManager();

        void Update(float deltaTime);
        void Render(SDL_Renderer& renderer);
        void ChangeScene(std::unique_ptr<Scene> newScene);

    private:
        std::unique_ptr<Scene> currentScene;
};