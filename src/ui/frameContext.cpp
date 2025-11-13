#include <frameContext.hpp>
#include <classes/frame.hpp>

WeeHub::Context::Context(WeeHub::Frame *initialFrame) {
    this->TransitionTo(initialFrame);
};

void WeeHub::Context::TransitionTo(WeeHub::Frame *newFrame) {
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