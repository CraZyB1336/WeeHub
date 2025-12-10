#include "SceneManager.h"
#include "MenuScene.h"

SceneManager::SceneManager(){
    currentScene = std::make_unique<MenuScene>();
}

SceneManager::~SceneManager(){}

void SceneManager::Render(Renderer& renderer){
    if(currentScene){
        currentScene->Render(renderer);
    }
}