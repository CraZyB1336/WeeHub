#include "Camera.h"
#include <SDL3/SDL_opengl.h>
#include <glm/gtc/type_ptr.hpp>

Camera::Camera(float width, float height) {
    // Set screen sizes
    this->screenSize[0] = width;
    this->screenSize[1] = height;

    glm::mat4 yomama = glm::ortho(0.0f, width, 0.0f, height, -1.0f, 1.0f);
}