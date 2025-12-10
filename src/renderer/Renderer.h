#pragma once

#include <SDL3/SDL.h>
#include "Renderer.h"

class Renderer{
    public:
        Renderer(SDL_Window* window);
        ~Renderer();

        void Clear();

        void Present();

    private:
        SDL_GLContext glContext;
        SDL_Window* window;
};