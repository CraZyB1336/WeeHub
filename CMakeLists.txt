cmake_minimum_required(VERSION 3.16)
project(Weehub CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optional: define output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")


# Add vendored SDL3 if you have it
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
# Optional: SDL_ttf if vendored
# add_subdirectory(vendored/SDL_ttf EXCLUDE_FROM_ALL)

# Find system libraries
find_package(OpenGL REQUIRED)

# Main executable
add_executable(${PROJECT_NAME} ${SOURCES})


# Link libraries
target_link_libraries(WeeHub PRIVATE SDL3::SDL3-shared OpenGL::GL)
# If SDL_ttf installed:
# target_link_libraries(WeeHub PRIVATE SDL3::SDL3_ttf)