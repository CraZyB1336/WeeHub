#include "SceneManager.h"
#include "MenuScene.h"

SceneManager::SceneManager(){
    currentScene = std::make_unique<MenuScene>();
}

SceneManager::~SceneManager(){}

void SceneManager::Update(int deltaTime){
    if(currentScene){
        currentScene->Update(deltaTime);
    }
}

void SceneManager::Render(SDL_Renderer& renderer){
    if(currentScene){
        currentScene->Render(renderer);
    }
}