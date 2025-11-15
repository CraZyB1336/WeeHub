#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <vector>

namespace WeeHub
{
    struct ImageData
    {
        GLuint imageID;
        int width, height;
    };

    struct GIFFrame
    {
        GLuint frame;
        int delay;
    };

    struct GIFData
    {
        std::vector<GLuint> frames;
        std::vector<int> delays;
        int frameAmount;
        int width, height;
        int current_frame = 0;
        float timer = 0.0;
    };

    /**
     * Returns a pointer to an imageTexture ID along with other data.
     */
    ImageData* loadImageFromPath(const char* fileName);

    /**
     * Returns a pointer to an gifTextures along with other data.
     */
    GIFData* loadGIFFromPath(const char* fileName);
}