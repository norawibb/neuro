cmake_minimum_required(VERSION 3.5.0)
project(neuro VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# Common SDL2 for the original neuro
find_package(SDL2 REQUIRED)

# Additional dependencies for the visualizer
set(OpenGL_GL_PREFERENCE "GLVND")
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

# Define imgui sources
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/visualizer/imgui)
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
    ${IMGUI_DIR}/imgui_demo.cpp      # Optional, if you need demo features
    ${IMGUI_DIR}/imgui_tables.cpp    # Optional, if you're using tables
)

# Original Neuro executable in C
add_executable(neuro 
    neurotron/main.c 
    neurotron/neurotron.c 
    neurotron/utilities.c
)
target_link_libraries(neuro PRIVATE SDL2::SDL2)

# Visualizer executable in C++
add_executable(neuro_visualizer 
    visualizer/main.cpp 
    ${IMGUI_SOURCES}
)

target_link_libraries(neuro_visualizer PRIVATE ${OPENGL_LIBRARIES})
target_link_libraries(neuro_visualizer PRIVATE GLEW::GLEW)
target_link_libraries(neuro_visualizer PRIVATE glfw)
target_include_directories(neuro_visualizer PRIVATE ${IMGUI_DIR})
target_include_directories(neuro_visualizer PRIVATE ${OPENGL_INCLUDE_DIR})
target_include_directories(neuro_visualizer PRIVATE ${GLEW_INCLUDE_DIRS})
target_include_directories(neuro_visualizer PRIVATE ${GLM_INCLUDE_DIRS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
