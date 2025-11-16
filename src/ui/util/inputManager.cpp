#include "inputManager.hpp"

using namespace WeeHub;

InputManager *InputManager::pinstance = nullptr;
std::mutex InputManager::mtx;

InputManager *InputManager::GetInstance()
{
    std::lock_guard<std::mutex> lock(mtx);
    if (pinstance == nullptr)
    {
        pinstance = new InputManager();
    }
    return pinstance;
}

void InputManager::AttachKeySubscriber(KeyInputSubscriber *callback)
{
    if (callback != nullptr)
        keyInputSubscriber.push_back(callback);
}

void InputManager::DetachKeySubscriber(KeyInputSubscriber *callback)
{
    if (callback != nullptr)
        keyInputSubscriber.remove(callback); // Safe since it does nothing if element is not inside
}

void InputManager::AttachMouseSubscriber(MouseInputSubscriber *callback)
{
    if (callback != nullptr)
        mouseInputSubscriber.push_back(callback);
}

void InputManager::DetachMouseSubscriber(MouseInputSubscriber *callback)
{
    if (callback != nullptr)
        mouseInputSubscriber.remove(callback); // Safe since it does nothing if element is not inside
}

void InputManager::CallKeySubscribers(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    GLFW_KEY_A;

    for (KeyInputSubscriber *subscriber : keyInputSubscriber)
    {
        subscriber->callback(key);
    }
}