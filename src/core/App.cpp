#include "App.h"
#include <iostream>
#include <SDL3/SDL_opengl.h>

App::App(): isRunning(true)
{
    window = std::make_unique<Window>(800, 600, "WeeHub");
    renderer = window->sdl_renderer;
    sceneManager = std::make_unique<SceneManager>(renderer);
}
App::~App()
{}

float nowTime;
float prevTime;

void App::Run(){
    while(isRunning){
        nowTime = SDL_GetTicks();
        deltaTime =( nowTime-prevTime)/1000.0f;
        Update(deltaTime);
        Render();
        fpsCounter++;
        deltaTime = SDL_GetTicks() - deltaTime;
        prevTime = nowTime;
    }
    SDL_Quit();
}

// void App::ProcessEvents(){
//     // Process input events
// }

void App::Update(float deltaTime){
    sceneManager->Update(deltaTime);
}

void App::Render(){  
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    while (SDL_PollEvent(&event)){
        if(event.type == SDL_EVENT_QUIT){
            isRunning = false;
        }
    }
    sceneManager->Render(*renderer);
}