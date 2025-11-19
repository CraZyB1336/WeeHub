cmake_minimum_required(VERSION 3.15)

project(WeeHub)

file (GLOB_RECURSE  PROJECT_HEADERS     src/*.hpp
                                        src/*.h)
file (GLOB_RECURSE  PROJECT_SOURCES     src/*.cpp
                                        src/*.c)

find_package(fmt CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(WeeHub ${PROJECT_SOURCES}
                      ${PROJECT_HEADERS})

target_link_libraries(WeeHub 
                      PRIVATE fmt::fmt
                      PRIVATE imgui::imgui
                      ${OPENGL_LIBRARIES}
                      )