#pragma once

#include <SDL3/SDL.h>
#include "Renderer.h"
#include "../utils/Color.h"

class Renderer{
    public:
        Renderer(SDL_Window* window);
        ~Renderer();

        void Clear();

        void DrawQuad(float x, float y, float width, float height, const Color& color);

        void Present();

    private:
        SDL_GLContext glContext;
        SDL_Window* window;
};