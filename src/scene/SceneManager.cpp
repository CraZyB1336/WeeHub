#include "SceneManager.h"
#include "MenuScene.h"

SceneManager::SceneManager(SDL_Renderer* renderer){
    currentScene = std::make_unique<MenuScene>(renderer);
}

SceneManager::~SceneManager(){}

void SceneManager::Render(SDL_Renderer& renderer){
    if(currentScene){
        currentScene->Render(renderer);
    }
}