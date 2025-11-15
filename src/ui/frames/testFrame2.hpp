#include "../util/frame.hpp"
#include "../util/imageLoader.hpp"
#include <imgui_impl_opengl3.h>
#include <imgui_impl_opengl3_loader.h>
#include <imgui_impl_glfw.h>

namespace WeeHub
{
    class TestFrame2 : public Frame {
    private:
        ImageData* imgData = nullptr;
        GIFData* gifData = nullptr;

    public:
        char *newString;
        TestFrame2(const char *frameName, const char *additionalParameter);

        void constructFrame(ImGuiWindowFlags &windowFlags) override;
        void renderFrame() override;

        ~TestFrame2();
    };
}