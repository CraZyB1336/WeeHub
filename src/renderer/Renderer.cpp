#include "Renderer.h"
#include <iostream>
#include <SDL3/SDL_opengl.h>

Renderer::Renderer(SDL_Window* window) 
{
    this->window = window;
    glContext = SDL_GL_CreateContext(window);
    if(!glContext){
        std::cerr << "SDL_GL_CreateContext failed: " << SDL_GetError() << std::endl;
    }
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

Renderer::~Renderer(){
    if(glContext){
        SDL_GL_DestroyContext(glContext);
    }
}
void Renderer::Clear(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Renderer::Present(){
    SDL_GL_SwapWindow(this->window);
}


void Renderer::DrawQuad(float x, float y, float width, float height, const Color& color){
    glBegin(GL_QUADS);
    glColor3f(color.r, color.g, color.b);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}