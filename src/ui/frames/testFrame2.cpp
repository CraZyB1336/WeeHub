#include "testFrame2.hpp"
#include <fmt/core.h>
#include <fmt/color.h>
#include <iostream>

TestFrame2::TestFrame2(const char *frameName, const char *additionalParameter) : Frame(frameName) {
    newString = new char[strlen(additionalParameter) + 1];
    strcpy(newString, additionalParameter);
}

// Base destructor should be called here
TestFrame2::~TestFrame2() {
    delete[] newString;
}

void TestFrame2::constructFrame(ImGuiWindowFlags &windowFlags) {
    // Window
    ImGui::Begin("Hello, im not Gui!", nullptr, windowFlags);
    ImGui::Text("Welcome to Dear not ImGui!");
    ImGui::Text("This is a basic not example window.");
    ImGui::Spacing();
    if (ImGui::Button("do not Click me!"))
    {
        fmt::print(fmt::emphasis::bold | fg(fmt::color::sky_blue), "[WeeHub] ");
        fmt::print("Button was clicked!\n");
    }

    ImGui::End();
}

void TestFrame2::renderFrame() {
    ImGui::Render();
}