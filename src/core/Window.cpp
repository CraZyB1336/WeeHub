#include "Window.h"
#include <iostream>
#include <SDL3/SDL_opengl.h>

Window::Window(int w, int h, const std::string& title)
    : width(w), height(h), shouldClose(false), sdl_window(nullptr)
{
    if(!SDL_Init(SDL_INIT_VIDEO)){
        throw std::runtime_error("Failed to initialize SDL");
    }

    sdl_window = SDL_CreateWindow(
        title.c_str(),
        w,h, SDL_WINDOW_OPENGL
    );

    if (!sdl_window){
        SDL_Quit();
        throw std::runtime_error("Failed to create SDL Window");
    }

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    SDL_Log("Window created: %s (%dx%d)", title.c_str(), w, h);
}

Window::~Window(){
    if(sdl_window){
        SDL_DestroyWindow(sdl_window);
    }
}

