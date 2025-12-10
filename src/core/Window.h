#pragma once

#include <SDL3/SDL.h>
#include <string>

class Window{
    public:
        Window(int widt = 800, int height = 600, const std::string& title = "WeeHub");
        ~Window();

        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;

        void Show();
        void SwapBuffers();
        bool ShouldClose() const;
        void Close();
        SDL_Window* GetNativeWindow() const;
        int GetWidth() const;
        int GetHeight() const;
        SDL_Window* sdl_window;
        SDL_Renderer* sdl_renderer;

    private:
        int width;
        int height;
        bool shouldClose;
};