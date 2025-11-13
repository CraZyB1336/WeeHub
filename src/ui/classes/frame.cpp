#include <frame.hpp>
#include <fmt/core.h>
#include <fmt/color.h>

WeeHub::Frame::Frame(const char *frameName)
{
    name = new char[strlen(frameName) + 1];
    strcpy(name, frameName);
    fmt::print(fmt::emphasis::bold | fg(fmt::color::sky_blue), "[WeeHub] ");
    fmt::print("Initialized frame '%s'\n", name);
}

void WeeHub::Frame::setContext(WeeHub::Context *newContext)
{
    this->context = newContext;
}

WeeHub::Frame::~Frame()
{
    delete[] name;
}