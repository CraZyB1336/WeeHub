#pragma once

#include <memory>
#include "Scene.h"
#include "../renderer/Renderer.h"

class SceneManager{
    public:
        SceneManager();
        ~SceneManager();

        void Update(int deltaTime);
        void Render(SDL_Renderer& renderer);
        void ChangeScene(std::unique_ptr<Scene> newScene);

    private:
        std::unique_ptr<Scene> currentScene;
};