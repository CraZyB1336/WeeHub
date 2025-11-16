#ifndef WEEHUB_CONTEXT
#define WEEHUB_CONTEXT

#include "util/frame.hpp"
#include <mutex>
#include <string>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_opengl3_loader.h>
#include <imgui_impl_glfw.h>


namespace WeeHub 
{
    class Context 
    {
        private:
            // Singleton properties
            static Context *pinstance;
            static std::mutex mtx;
            float scale = 1.0f;
        
        protected:
            // Protected constructors for Singleton
            Context() : currentFrame(nullptr) {}
            Frame *currentFrame;
            
        public:
            Context(Context &other) = delete;
            void operator=(const Context &) = delete;

            static Context *GetInstance();

            void setScale(float scale);
            float getScale();
            void TransitionTo(Frame *newFrame);
            void constructFrame(int &windowWidth, int &windowHeight, ImGuiWindowFlags &windowFlags, float deltaTime, float scale);
            void renderFrame();
            ~Context();
    };
}

#endif
