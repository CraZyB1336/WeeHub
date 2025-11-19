#include "bootFrame.hpp"
#include "../frameContext.hpp"
#include <fmt/core.h>
#include <fmt/color.h>
#include <iostream>

using namespace WeeHub;
BootFrame::BootFrame(const char *frameName) : Frame(frameName) 
{
    continuumBold = io.Fonts->AddFontFromFileTTF("resources/fonts/contb.ttf", 256.0f);
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
    ImGui::SetWindowFontScale((220.0f / 256.0f) * context->getScale());
    ImGui::PushFont(continuumBold);
    const char *title = "WeeHub";
    ImVec2 textSize = ImGui::CalcTextSize(title);
    ImVec2 windowSize = ImGui::GetWindowSize();
    ImVec2 pos = ImVec2((windowSize.x - textSize.x) * 0.5, (windowSize.y - textSize.y) * 0.5);

    ImGui::SetCursorPos(pos);
    ImGui::Text("WeeHub");
    ImGui::PopFont();
    ImGui::End();
}

void BootFrame::renderFrame() {
    ImGui::Render();
}