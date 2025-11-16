cmake_minimum_required(VERSION 3.15)

project(WeeHub)

set(SOURCES
    "src/main.cpp"
    "src/ui/frameContext.cpp"
    "src/ui/util/frame.cpp"
    "src/ui/util/imageLoader.cpp"
    "src/ui/util/inputManager.cpp"
    "src/ui/frames/bootFrame.cpp"
    "src/ui/frames/testFrame.cpp"
    "src/ui/frames/testFrame2.cpp"
)

find_package(fmt CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(WeeHub ${SOURCES})

target_link_libraries(WeeHub 
                      PRIVATE fmt::fmt
                      PRIVATE imgui::imgui
                      ${OPENGL_LIBRARIES}
                      )