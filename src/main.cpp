#define NOMINMAX
#include <fmt/core.h>
#include <fmt/color.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_opengl3_loader.h>
#include <imgui_impl_glfw.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "ui/frameContext.hpp"
#include "ui/frames/bootFrame.hpp"
#include "ui/util/inputManager.hpp"

ImVec4 clear_color = ImVec4(0.45f, 0.23f, 0.86f, 1.0f);

const float REF_WIDTH = 1920.0f;
const float REF_HEIGHT = 1080.0f;

// TODO, move to a global settings file
const float UPSCALED_FONT = 48.0f;
const float fontSize = 24.0f;

// Singletons
WeeHub::Context *frameContext = WeeHub::Context::GetInstance();
WeeHub::InputManager *inputManager = WeeHub::InputManager::GetInstance();

bool windowed = false;

int main() {
    fmt::print(fmt::emphasis::bold | fg(fmt::color::sky_blue), "[WeeHub] ");
    fmt::print("Booting WeeHub\n");

    // Setup glfw
    if (!glfwInit())
        return -1;

    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

    GLFWwindow *window;

    if (windowed)
        window = glfwCreateWindow(REF_WIDTH / 2, REF_WIDTH / 2, "ImGui Basic", NULL, NULL);
    else
        window = glfwCreateWindow(mode->width, mode->height, "ImGui Basic", monitor, NULL);
    
    if (window == NULL)
        return -1;

    // Defining GLSL version
    const char *glslVersion = "#version 330";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable VSYNC

    // ImGui Setup
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();

    // Initialize default font
    ImFontConfig config;
    config.OversampleH = 3;
    config.OversampleV = 3;
    config.SizePixels = 48.0f;

    io.FontDefault = io.Fonts->AddFontDefault(&config);

    ImGuiWindowFlags windowFlags = 0;
    windowFlags |= ImGuiWindowFlags_NoTitleBar;
    windowFlags |= ImGuiWindowFlags_NoResize;
    windowFlags |= ImGuiWindowFlags_NoMove;
    windowFlags |= ImGuiWindowFlags_NoCollapse;

    // Dark color theme
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glslVersion);

    // Initialize first frame
    WeeHub::Frame *bootFrame = new WeeHub::BootFrame("BootFrame");

    frameContext->TransitionTo(bootFrame);

    // Input stuff
    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        inputManager->CallKeySubscribers(window, key, scancode, action, mods);
    });

    while (!glfwWindowShouldClose(window))
    {
        int windowWidth, windowHeight;
        glfwGetWindowSize(window, &windowWidth, &windowHeight);
        float scale = std::min(windowWidth / REF_WIDTH, windowHeight / REF_HEIGHT);

        frameContext->setScale(scale);

        glfwPollEvents();

        frameContext->constructFrame(windowWidth, windowHeight, windowFlags, io.DeltaTime, scale);
        frameContext->renderFrame();

        // Cleanup frame
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}