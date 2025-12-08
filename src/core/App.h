#pragma once

#include <memory>
#include "Window.h"

class Window;
class Renderer;
class Input;
class SceneManager;
class AudioManager;
class Timer;
class App {
    public:
        App();
        ~App();

        void Run();

    private:
        void ProcessEvents();
        void Update();
        void Render();

        std::unique_ptr<Window> window;
        // std::unique_ptr<Renderer> renderer;
        // std::unique_ptr<Input> input;
        // std::unique_ptr<SceneManager> sceneManager;
        // std::unique_ptr<AudioManager> audioManager;
        // std::unique_ptr<Timer> timer;

        bool isRunning;
        SDL_Event event;
};