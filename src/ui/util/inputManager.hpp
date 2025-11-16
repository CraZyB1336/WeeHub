#ifndef WEEHUB_INPUT
#define WEEHUB_INPUT
#pragma once

#include <mutex>
#include <list>
#include <functional>
#include <GLFW/glfw3.h>

namespace WeeHub
{
    enum KeyOptions : uint8_t
    {
        KEY_PRESSED = 1 << 0, // 0000 0001
        KEY_RELEASED = 1 << 1 // 0000 0010
    };

    struct KeyInputSubscriber
    {
        std::function<void(GLFWwindow*, int)> callback;
        uint8_t options;
    };

    enum MouseOptions : uint8_t
    {
        LEFT_CLICK = 1 << 0, // 0000 0001
        RIGHT_CLICK = 1 << 1, // 0000 0010
        MIDDLE_CLICK = 1 << 2, // 0000 0100
        MIDDLE_SCROLL = 1 << 3, // 0000 1000

        // Options for listening for each
        LEFT_PRESSED = 1 << 4, // 0001 0000
        LEFT_RELEASED = 1 << 5, // 0010 0000
        RIGHT_PRESSED = 1 << 6, // 0100 0000
        RIGHT_RELEASED = 1 << 7 // 1000 0000
    };

    struct MouseInputSubscriber
    {
        std::function<void(GLFWwindow*)> callback;
        uint8_t options;
    };

    /**
     * This will act as an additional inputManager above Dear ImGUI
     */
    class InputManager
    {
        private:
            // Singleton properties
            static InputManager *pinstance;
            static std::mutex mtx;

            // Using lists here since we will iterate through all. NO random access
            std::list<KeyInputSubscriber*> keyInputSubscriber;
            std::list<MouseInputSubscriber*> mouseInputSubscriber;

        protected:
            // Protected constructor for singleton
            InputManager() {};
        
        public:
            InputManager(InputManager *other) = delete;
            void operator=(const InputManager &) = delete;

            static InputManager *GetInstance();

            void AttachKeySubscriber(KeyInputSubscriber *callback);
            void DetachKeySubscriber(KeyInputSubscriber *callback);

            void AttachMouseSubscriber(MouseInputSubscriber *callback);
            void DetachMouseSubscriber(MouseInputSubscriber *callback);

            void CallKeySubscribers(GLFWwindow *window, int key, int scancode, int action, int mods);
            // void CallMouseSubscribers();
    };
}

#endif