#include "frameContext.hpp"
#include <fmt/core.h>
#include <fmt/color.h>

using namespace WeeHub;
Context::Context()
{
    inputManager = InputManager::GetInstance();
    currentFrame = nullptr;

    // Setting global keyboard handlers
    exitInput = new KeyInputSubscriber;
    exitInput->callback = [this](GLFWwindow *window, int key) {
        if (key == GLFW_KEY_Q)
        {
            fmt::print(fmt::emphasis::bold | fg(fmt::color::sky_blue), "[WeeHub] ");
            fmt::print("Closing WeeHub. Goodbye!\n");
            glfwSetWindowShouldClose(window, GL_TRUE);
        }
    };

    inputManager->AttachKeySubscriber(exitInput);
    exitInput->options = KEY_RELEASED;
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
    delete exitInput;
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