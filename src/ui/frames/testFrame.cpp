#include "testFrame.hpp"
#include "../frameContext.hpp"
#include "testFrame2.hpp"
#include <fmt/core.h>
#include <fmt/color.h>
#include <iostream>

TestFrame::TestFrame(const char *frameName, const char *additionalParameter) : Frame(frameName) {
    newString = new char[strlen(additionalParameter) + 1];
    strcpy(newString, additionalParameter);
}

// Base destructor should be called here
TestFrame::~TestFrame() {
    delete[] newString;
}

void TestFrame::constructFrame(ImGuiWindowFlags &windowFlags) {
    // Window
    ImGui::Begin("Hello, ImGui!", nullptr, windowFlags);
    ImGui::Text("Welcome to Dear ImGui!");
    ImGui::Text("This is a basic example window.");
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