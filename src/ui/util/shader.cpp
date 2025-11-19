#include "shader.hpp"
#include <glad/glad.h>

using namespace WeeHub;
Shader::Shader()                    { programID = glCreateProgram(); }
void Shader::activate()             { glUseProgram(programID); }
void Shader::deactivate()           { glUseProgram(0); }
unsigned int Shader::getProgramID() { return programID; }
void Shader::destroy()              { glDeleteProgram(programID);}

std::string Shader::getSource(std::string const &filename)
{
    std::ifstream fd(filename.c_str());

    if (fd.fail())
    {
        fprintf(stderr, "Error locating shader file: \"%s\"\n", filename.c_str());
        return nullptr;
    }

    std::string content(std::istreambuf_iterator<char>(fd), (std::istreambuf_iterator<char>()));

    std::istringstream iss(content);
    std::string line;
    std::string result;

    // Remove #version from file
    while (std::getline(iss, line))
    {
        std::string trimmed = line;
        trimmed.erase(0, trimmed.find_first_not_of(" \t"));

        if (trimmed.find("#version") != 0)
        {
            result += line + "\n";
        }
    }

    return result;
}

void Shader::attachWithSource(std::string const &filename, std::string const &sourceFile, bool filenameIsExtension)
{
    auto shader = create(filename, filenameIsExtension);
    std::string combinedWithVersion = SHADER_VERSION + '\n' + sourceFile;
    const char* source = combinedWithVersion.c_str();
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    // Display errors
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (!status)
    {
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        std::unique_ptr<char[]> buffer(new char[length]);
        glGetShaderInfoLog(shader, length, nullptr, buffer.get());
        fprintf(stderr, "%s\n%s", filename.c_str(), buffer.get());
    }

    assert(status);
    
    // Attach and free memory.
    glAttachShader(programID, shader);
    glDeleteShader(shader);
}

void Shader::attach(std::string const &filename)
{
    // Create shader object
    std::string sourceString = getSource(filename).c_str();
    attachWithSource(filename, sourceString, false);
}

std::string Shader::combine(std::string const &source1, std::string const &source2) { return source1 + source2; }

void Shader::link()
{
    glLinkProgram(programID);

    glGetProgramiv(programID, GL_LINK_STATUS, &status);
    if (!status)
    {
        glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &length);
        std::unique_ptr<char[]> buffer(new char[length]);
        glGetProgramInfoLog(programID, length, nullptr, buffer.get());
        fprintf(stderr, "%s\n%s", buffer.get());
    }

    assert(status);
}

unsigned int Shader::getUniformFromName(std::string const &uniformName)
{
    return glGetUniformLocation(programID,  uniformName.c_str());
}

unsigned int create(std::string const &filename, bool filenameIsExtension)
{
    std::string ext = filename;

    if (!filenameIsExtension)
    {
        auto idx = filename.rfind(".");
        ext = filename.substr(idx + 1);
    }

    if      (ext == "comp") return glCreateShader(GL_COMPUTE_SHADER);
    else if (ext == "frag") return glCreateShader(GL_FRAGMENT_SHADER);
    else if (ext == "vert") return glCreateShader(GL_VERTEX_SHADER);
    else                    return false;
}