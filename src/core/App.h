#pragma once

#include <memory>
#include "Window.h"
#include "../renderer/Renderer.h"
#include "../scene/SceneManager.h"

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
        void Update(int deltaTime);
        void Render();

        std::unique_ptr<Window> window;
        SDL_Renderer* renderer;
        // std::unique_ptr<Input> input;
        std::unique_ptr<SceneManager> sceneManager;
        // std::unique_ptr<AudioManager> audioManager;

        bool isRunning;
        SDL_Event event;
        int deltaTime;
        int fpsCounter;
};