#define STB_IMAGE_IMPLEMENTATION
#include "imageLoader.hpp"
#include <fstream>
#include <fmt/core.h>
#include <fmt/color.h>

namespace WeeHub
{
    ImageData* loadImageFromPath(const char* fileName)
    {
        ImageData* imgData = new ImageData;
        GLuint imageID;
        int imageWidth, imageHeight;

        unsigned char*  image_data = stbi_load(fileName, &imageWidth, &imageHeight, NULL, 4);
        glGenTextures(1, &imageID);
        glBindTexture(GL_TEXTURE_2D, imageID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);

        stbi_image_free(image_data);

        imgData->imageID = imageID;
        imgData->width = imageWidth;
        imgData->height = imageHeight;

        return imgData;
    }

    GIFData* loadGIFFromPath(const char* fileName)
    {
        GIFData* gifData = new GIFData;
        int error; 

        // Have to parse the gif into memory
        std::ifstream file(fileName, std::ios::binary | std::ios::ate);
        if (!file.is_open())
        {
            fmt::print(fmt::emphasis::bold | fg(fmt::color::sky_blue), "[WeeHub]");
            fmt::print(fmt::emphasis::bold | fg(fmt::color::indian_red), "[Error] ");
            fmt::print("Could not find GIF / GIF location");
        }

        size_t fileSize = file.tellg();
        file.seekg(0, std::ios::beg);

        std::vector<unsigned char> buffer(fileSize);
        file.read(reinterpret_cast<char*>(buffer.data()), fileSize);
        file.close();

        // Loading the frames
        int* delays = nullptr;
        int numberOfFrames = 0;
        int width, height, channels;

        unsigned char* gif_data = stbi_load_gif_from_memory(
            buffer.data(),
            static_cast<int>(fileSize),
            &delays,
            &width,
            &height,
            &numberOfFrames,
            &channels,
            4
        );

        if (!gif_data)
        {
            fmt::print(fmt::emphasis::bold | fg(fmt::color::sky_blue), "[WeeHub]");
            fmt::print(fmt::emphasis::bold | fg(fmt::color::indian_red), "[Error] ");
            fmt::print("Could not load GIF from memory");
        }

        size_t frameSize = width * height * 4;
        for (int i = 0; i < numberOfFrames; i++)
        {
            GLuint frameID;
            glGenTextures(1, &frameID);
            glBindTexture(GL_TEXTURE_2D, frameID);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            unsigned char* frameData = gif_data + (i * frameSize);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, frameData);

            gifData->frames.push_back(frameID);
            gifData->delays.push_back(delays[i]);
        }

        gifData->width = width;
        gifData->height = height;
        gifData->frameAmount = numberOfFrames;

        // Unbind
        glBindTexture(GL_TEXTURE_2D, 0);

        stbi_image_free(gif_data);
        free(delays);

        return gifData;
    }

    GLuint getCurrentGIFFrame(GIFData* gifData, float deltaTime)
    {
        int currentFrameDelay = gifData->delays[gifData->current_frame];
        gifData->timer += deltaTime * 1000.0f;

        // Check for transition of frame
        if (gifData->timer >= currentFrameDelay)
        {
            gifData->timer = 0;
            gifData->current_frame = (gifData->current_frame + 1) % gifData->frameAmount;
        }

        return gifData->current_frame;
    }
}