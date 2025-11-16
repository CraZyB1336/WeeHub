#include "testFrame.hpp"
#include "testFrame2.hpp"
#include "../frameContext.hpp"
#include <fmt/core.h>
#include <fmt/color.h>
#include <iostream>

using namespace WeeHub;
TestFrame::TestFrame(const char *frameName, const char *additionalParameter) : Frame(frameName) 
{
    newString = new char[strlen(additionalParameter) + 1];
    strcpy(newString, additionalParameter);

    Context *context = Context::GetInstance();


    continuumBold = io.Fonts->AddFontFromFileTTF("resources/fonts/contb.ttf", 48.0f);
    io.FontGlobalScale = (24.0f / 48.0f) * context->getScale();
}

// Base destructor should be called here
TestFrame::~TestFrame() {
    delete[] newString;
}

void TestFrame::constructFrame(ImGuiWindowFlags &windowFlags, float deltaTime) {
    // Window
    ImGui::Begin("Sup", nullptr, windowFlags);
    ImGui::PushFont(continuumBold);
    ImGui::Text("WeeHub.. YEAH BABY LET'S GO!");
    ImGui::PopFont();
    ImGui::Spacing();
    if (ImGui::Button("Click me to transition!"))
    {
        Context* context = Context::GetInstance();
        context->TransitionTo(new TestFrame2("Yodada", "yodad2"));
    }
    ImGui::End();
}

void TestFrame::renderFrame() {
    ImGui::Render();
}