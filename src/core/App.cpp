#include "App.h"
#include <iostream>
#include <SDL3/SDL_opengl.h>

App::App(): isRunning(true)
{
    window = std::make_unique<Window>(800, 600, "WeeHub");
    renderer = window->sdl_renderer;
    sceneManager = std::make_unique<SceneManager>();
}
App::~App()
{}

void App::Run(){
    while(isRunning){
        deltaTime = SDL_GetTicks();
        // ProcessEvents();
        // Update(deltaTime);
        Render();
        fpsCounter++;
        deltaTime = SDL_GetTicks() - deltaTime;
        std::cout << "Frame Time: " << deltaTime << " ms, FPS: " << (1000.0f / deltaTime) << "\r";
    }
    SDL_Quit();
}

// void App::ProcessEvents(){
//     // Process input events
// }

void App::Update(){
    // Update application state
}

void App::Render(){  
    while (SDL_PollEvent(&event)){
        if(event.type == SDL_EVENT_QUIT){
            isRunning = false;
        }
    }
    sceneManager->Render(*renderer);
}