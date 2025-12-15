#include "Window.h"
#include <iostream>
#include <SDL3/SDL_opengl.h>

Window::Window(int w, int h, const std::string& title)
    : width(w), height(h), shouldClose(false), sdl_window(nullptr), sdl_renderer(nullptr)
{
    if(!SDL_Init(SDL_INIT_VIDEO)){
        throw std::runtime_error("Failed to initialize SDL");
    }

    sdl_window = SDL_CreateWindow(
        title.c_str(),
        w,h, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
    );
    if (!sdl_window){
        SDL_Quit();
        throw std::runtime_error("Failed to create SDL Window");
    }

    sdl_renderer = SDL_CreateRenderer(sdl_window, NULL);
    if(!sdl_renderer){
        SDL_DestroyWindow(sdl_window);
        SDL_Quit();
        throw std::runtime_error("Failed to create SDL Renderer");
    }

    SDL_Log("Window created: %s (%dx%d)", title.c_str(), w, h);
}

Window::~Window(){
    if(sdl_window){
        SDL_DestroyRenderer(sdl_renderer);
        SDL_DestroyWindow(sdl_window);
    }
}

