#include "bootFrame.hpp"
#include "../frameContext.hpp"
#include <fmt/core.h>
#include <fmt/color.h>
#include <iostream>

using namespace WeeHub;
BootFrame::BootFrame(const char *frameName) : Frame(frameName) 
{
    continuumBold = io.Fonts->AddFontFromFileTTF("resources/fonts/contb.ttf", 128.0f);
}

// Base destructor should be called here
BootFrame::~BootFrame() {}

void BootFrame::constructFrame(ImGuiWindowFlags &windowFlags, float deltaTime) {
    Context *context = Context::GetInstance();
    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImVec2 center = viewport->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(0.5f, 0.5f));

    // Window
    ImGui::Begin("Yo", nullptr, windowFlags);
    ImGui::SetWindowFontScale((80.0f / 128.0f) * context->getScale());
    ImGui::PushFont(continuumBold);
    ImGui::Text("WeeHub");

    ImGui::SetWindowFontScale((48.0f / 128.0f) * context->getScale());
    ImGui::Text("By Christopher and David");
    ImGui::PopFont();
    ImGui::End();
}

void BootFrame::renderFrame() {
    ImGui::Render();
}