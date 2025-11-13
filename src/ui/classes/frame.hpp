#ifndef WEEHUB_FRAME
#define WEEHUB_FRAME

#include <imgui_impl_opengl3.h>
#include <imgui_impl_opengl3_loader.h>
#include <frameContext.hpp>

using namespace WeeHub;
// Abstract class for frame. Declare 
class Frame {
    private:
        char *name;

    protected:
        Context *context;

    public:
        Frame(const char *frameName);

        void setContext(Context *newContext);

        // Virtual methods to construct frame and render frame
        virtual void constructFrame() = 0;
        virtual void renderFrame() = 0;

        // Derived class should define their own destructor
        virtual ~Frame();
};

#endif
