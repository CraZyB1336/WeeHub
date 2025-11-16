#include "frameContext.hpp"
#include <fmt/core.h>

using namespace WeeHub;
Context::Context()
{
    currentFrame = nullptr;
    exitInput = new KeyInputSubscriber;
    exitInput->callback = [this](int key) {
        fmt::print("Yoyoyo it worked");
    };
    exitInput->options = KEY_PRESSED;

    InputManager *inputManager = InputManager::GetInstance();
    inputManager->AttachKeySubscriber(exitInput);
}

void Context::TransitionTo(Frame *newFrame) {
    if (this->currentFrame != nullptr)
        delete this->currentFrame;
    this->currentFrame = newFrame;
}

void Context::constructFrame(int &windowWidth, int &windowHeight, ImGuiWindowFlags &windowFlags, float deltaTime, float scale)
{
    // Setup the frame in the context
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(windowWidth, windowHeight));

    // Generate the actual window
    this->currentFrame->constructFrame(windowFlags, deltaTime);
}

void Context::renderFrame()
{
    this->currentFrame->renderFrame();
}

Context::~Context()
{
    delete currentFrame;
}

Context *Context::pinstance = nullptr;
std::mutex Context::mtx;

// Singleton instance.
Context *Context::GetInstance() {
    std::lock_guard<std::mutex> lock(mtx);
    if (pinstance == nullptr)
    {
        pinstance = new Context();
    }
    return pinstance;
}

void Context::setScale(float scale) { this->scale = scale; }
float Context::getScale() { return this->scale; }