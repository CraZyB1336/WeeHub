add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE 
    main.cpp
    
    # Core
    core/App.cpp
    core/Window.cpp
    
    # Renderer
    renderer/Renderer.cpp
    renderer/Texture.cpp
    
    # UI
    ui/Channel.cpp
    ui/ChannelGrid.cpp
    ui/Cursor.cpp
    
    # Scene
    scene/Scene.cpp
    scene/MenuScene.cpp
    scene/SceneManager.cpp
    
    # Utils
    utils/Input.cpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)