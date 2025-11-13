#ifndef WEEHUB_CONTEXT
#define WEEHUB_CONTEXT

#include <classes/frame.hpp>
#include <mutex>
#include <string>

namespace WeeHub
{
    class Context {
        private:
            // Singleton properties
            static Context *pinstance;
            static std::mutex mutex;

            WeeHub::Frame *currentFrame;
        
        protected:
            Context(const std::string);
        
        public:
            Context(WeeHub::Frame *initialFrame);
            void TransitionTo(WeeHub::Frame *newFrame);
            void constructFrame();
            void renderFrame();
            ~Context();
    };
}

#endif
