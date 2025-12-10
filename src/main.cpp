#include <SDL3/SDL.h>
#include "core/App.h"
#include "../include/nuklear.h"

int main(int argc, char* argv[]) {
    try{
        App app;
        app.Run();
        SDL_Log("Exiting normaly");
        return 0;
    } catch (const std::exception& e) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unhandled exception: %s", e.what());
        return -1;
    }
}