#ifndef WEEHUB_SHADER
#define WEEHUB_SHADER
#pragma once

#include <cassert>
#include <fstream>
#include <memory>
#include <string>
#include <sstream>

namespace WeeHub
{
    const std::string SHADER_VERSION = "#version 330 core";

    class Shader
    {
        private:
            unsigned int programID;
            int status;
            int length;

        public:
            Shader();
            void activate();
            void deactivate();
            unsigned int getProgramID();
            void destroy();
            std::string getSource(std::string const &filename);

            void attach(std::string const &filename);
            void attachWithSource(std::string const &filename, std::string const &sourceFile, bool filenameIsExtension);
            std::string combine(std::string const &source1, std::string const &source2);

            void link();
            unsigned int getUniformFromName(std::string const &uniformName);
        
        private:
            unsigned int create(std::string const &filename, bool filenameIsExtension);
    };
};

#endif