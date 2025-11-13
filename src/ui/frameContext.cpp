#include <frameContext.hpp>
#include <classes/frame.hpp>

void WeeHub::Context::TransitionTo(Frame *newFrame) {
    if (this->currentFrame != nullptr)
        delete this->currentFrame;
    this->currentFrame = newFrame;
    this->currentFrame->setContext(this);
}

void WeeHub::Context::constructFrame()
{
    this->currentFrame->constructFrame();
}

void WeeHub::Context::renderFrame()
{
    this->currentFrame->renderFrame();
}

WeeHub::Context::~Context()
{
    delete currentFrame;
}

WeeHub::Context *pinstance = nullptr;
std::mutex WeeHub::Context::mtx;

// Singleton instance.
WeeHub::Context *WeeHub::Context::GetInstance() {
    std::lock_guard<std::mutex> lock(mtx);
    if (pinstance == nullptr)
    {
        pinstance = new Context();
    }
    return pinstance;
}