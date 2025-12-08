#include "App.h"
#include <iostream>
#include <SDL3/SDL_opengl.h>

App::App(): isRunning(true)
{
    window = std::make_unique<Window>(800, 600, "WeeHub");
}
App::~App()
{}

void App::Run(){
    while(isRunning){
        Render();
    }
    SDL_Quit();
}

void App::ProcessEvents(){
    // Process input events
}

void App::Update(){
    // Update application state
}

void App::Render(){
    while (SDL_PollEvent(&event)){
        if(event.type == SDL_EVENT_QUIT){
            isRunning = false;
        }
    }
    glClear(GL_COLOR_BUFFER_BIT);
    // Draw test quad
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex2f(-0.5f, -0.1f);
    glVertex2f(0.5f, -0.1f);
    glVertex2f(0.5f, 0.1f);
    glVertex2f(-0.5f, 0.1f);
    glEnd();

    window->SwapBuffers();
}