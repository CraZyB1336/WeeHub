#include "../util/frame.hpp"
#include <imgui_impl_opengl3.h>
#include <imgui_impl_opengl3_loader.h>
#include <imgui_impl_glfw.h>

namespace WeeHub
{
    class BootFrame : public Frame 
    {
        private:
            ImGuiIO &io = ImGui::GetIO();
            ImFont* continuumBold;

        public:
            BootFrame(const char *frameName);

            void constructFrame(ImGuiWindowFlags &windowFlags, float deltaTime) override;
            void renderFrame() override;

            ~BootFrame();
    };
}