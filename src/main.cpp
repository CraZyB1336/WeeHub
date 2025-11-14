#include <fmt/core.h>
#include <fmt/color.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_opengl3_loader.h>
#include <imgui_impl_glfw.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "ui/frameContext.hpp"
#include "ui/frames/testFrame.hpp"

ImVec4 clear_color = ImVec4(0.45f, 0.23f, 0.86f, 1.0f);
bool showDemo = true;

int main() {
    fmt::print(fmt::emphasis::bold | fg(fmt::color::sky_blue), "[WeeHub] ");
    fmt::print("Booting WeeHub\n");

    // Setup glfw
    if (!glfwInit())
        return -1;

    GLFWwindow *window = glfwCreateWindow(1280, 720, "ImGui Basic", NULL, NULL);
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
    io.FontGlobalScale = 2.5f;

    // Dark color theme
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glslVersion);

    ImGuiWindowFlags windowFlags = 0;
    windowFlags |= ImGuiWindowFlags_NoTitleBar;
    windowFlags |= ImGuiWindowFlags_NoResize;
    windowFlags |= ImGuiWindowFlags_NoMove;
    windowFlags |= ImGuiWindowFlags_NoCollapse;

    // Initialize Context singleton
    Context *frameContext = Context::GetInstance();
    Frame *testFrame = new TestFrame("Yomama Test", "additional");

    frameContext->TransitionTo(testFrame);

    while (!glfwWindowShouldClose(window))
    {
        int windowWidth, windowHeight;
        glfwGetWindowSize(window, &windowWidth, &windowHeight);

        glfwPollEvents();

        frameContext->constructFrame(windowWidth, windowHeight, windowFlags);
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