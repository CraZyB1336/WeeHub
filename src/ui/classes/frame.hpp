#ifndef WEEHUB_FRAME
#define WEEHUB_FRAME

#include <imgui_impl_opengl3.h>
#include <imgui_impl_opengl3_loader.h>
#include <frameContext.hpp>

namespace WeeHub
{
    // Abstract class for frame. Declare 
    class Frame {
        private:
            char *name;

        protected:
            WeeHub::Context *context;

        public:
            Frame(const char *frameName);

            void setContext(WeeHub::Context *newContext);

            virtual void constructFrame() = 0;
            virtual void renderFrame() = 0;


            virtual ~Frame();
    };
}

#endif