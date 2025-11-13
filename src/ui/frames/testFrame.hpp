#include <../classes/frame.hpp>

using namespace WeeHub;

class TestFrame : public Frame {
    public:
        TestFrame(const char *frameName, const char *additionalParameter);

        void constructFrame() override;
        void renderFrame() override;

        ~TestFrame();
};