#include "Window.h"
#include <iostream>
#include <SDL3/SDL_opengl.h>

Window::Window(int w, int h, const std::string& title)
    : width(w), height(h), shouldClose(false), window(nullptr), glContext(nullptr)
{
    if(!SDL_Init(SDL_INIT_VIDEO)){
        throw std::runtime_error("Failed to initialize SDL");
    }

    window = SDL_CreateWindow(
        title.c_str(),
        w,h, SDL_WINDOW_OPENGL
    );

    if (!window){
        SDL_Quit();
        throw std::runtime_error("Failed to create SDL Window");
    }

    glContext = SDL_GL_CreateContext(window);
    if (!glContext){
        std::cerr << "SDL_GL_CreateContext failed: " << SDL_GetError() << std::endl;
    }

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    SDL_Log("Window created: %s (%dx%d)", title.c_str(), w, h);
}

Window::~Window(){
    if(window){
        SDL_DestroyWindow(window);
    }
    if(glContext){
        SDL_GL_DestroyContext(glContext);
    }
}

void Window::SwapBuffers(){
    SDL_GL_SwapWindow(window);
}

