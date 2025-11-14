#include "../classes/frame.hpp"
#include <imgui_impl_opengl3.h>
#include <imgui_impl_opengl3_loader.h>
#include <imgui_impl_glfw.h>

// using namespace WeeHub;

class TestFrame : public Frame {
    public:
        char *newString;
        TestFrame(const char *frameName, const char *additionalParameter);

        void constructFrame(ImGuiWindowFlags &windowFlags) override;
        void renderFrame() override;

        ~TestFrame();
};