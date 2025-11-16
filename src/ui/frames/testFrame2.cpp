#include "testFrame2.hpp"
#include <fmt/core.h>
#include <fmt/color.h>
#include <iostream>
#include "../frameContext.hpp"

using namespace WeeHub;

TestFrame2::TestFrame2(const char *frameName, const char *additionalParameter) : Frame(frameName) {
    newString = new char[strlen(additionalParameter) + 1];
    strcpy(newString, additionalParameter);
    imgData = loadImageFromPath("resources/images/hasmter.jpg");
    gifData = loadGIFFromPath("resources/images/chinacat.gif");
}

// Base destructor should be called here
TestFrame2::~TestFrame2() {
    delete[] newString;

    if (imgData != nullptr)
        delete imgData;

    if (gifData != nullptr)
        delete gifData;
}

void TestFrame2::constructFrame(ImGuiWindowFlags &windowFlags, float deltaTime) {
    Context *context = Context::GetInstance();
    float scale = context->getScale();

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

    ImGui::Image(imgData->imageID, ImVec2(imgData->width * scale, imgData->height * scale));
    getCurrentGIFFrame(this->gifData, deltaTime);
    ImGui::Image(gifData->currentFrameID, ImVec2(gifData->width * scale, gifData->height * scale));
    ImGui::End();
}

void TestFrame2::renderFrame() {
    ImGui::Render();
}