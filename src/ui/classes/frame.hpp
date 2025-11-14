#ifndef WEEHUB_FRAME
#define WEEHUB_FRAME

#include <imgui_impl_opengl3.h>
#include <imgui_impl_opengl3_loader.h>

// using namespace WeeHub;
// Abstract class for frame. Declare 
class Frame {
    private:
        char *name;

    public:
        Frame(const char *frameName);

        // Virtual methods to construct frame and render frame
        virtual void constructFrame(ImGuiWindowFlags &windowFlags) = 0;
        virtual void renderFrame() = 0;

        // Derived class should define their own destructor
        virtual ~Frame();
};

#endif
