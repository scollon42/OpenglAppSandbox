cmake_minimum_required(VERSION 3.13)
project(OpengGLApp)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/third_party/glad/include)

add_executable(OpengGLApp
        src/third_party/glad/src/glad.c
        main.cpp
        src/core/application/Application.cpp
        src/core/application/Application.h
        src/utils/logger.h
        src/core/IScene.h
        src/utils/types.h
        src/core/math/Vector3D.cpp
        src/core/math/Vector3D.h
        src/core/math/Vector2D.cpp
        src/core/math/Vector2D.h
        src/core/application/input_event_type.h src/scene/BaseScene.cpp src/scene/BaseScene.h)

target_link_libraries(
        OpengGLApp
        GL
        glfw3
        rt
        m
        dl
        X11
        xcb
        Xau
        Xdmcp
        pthread
)