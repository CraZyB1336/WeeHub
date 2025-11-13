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
            static std::mutex mtx;
        
        protected:
            Context() {}
            ~Context() {}
            Frame *currentFrame;
            
        public:
            Context(Context &other) = delete;
            void operator=(const Context &) = delete;

            static Context *GetInstance();

            void TransitionTo(Frame *newFrame);
            void constructFrame();
            void renderFrame();
            ~Context();
    };
} 

#endif
