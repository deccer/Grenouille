cmake_minimum_required(VERSION 3.14)
project(Grenouille)

add_subdirectory(lib)

set(sourceFiles
    Application.cpp
)

set(headerFiles
    include/Grenouille/Application.hpp
)
add_library(Grenouille ${sourceFiles} ${headerFiles})

find_package(OpenGL REQUIRED)

target_include_directories(glfw PUBLIC include)
target_include_directories(glad PUBLIC include)
target_include_directories(imgui PUBLIC include)
target_include_directories(spdlog PUBLIC include)
target_include_directories(Grenouille PRIVATE include)

target_link_libraries(Grenouille PRIVATE glfw glad glm TracyClient spdlog imgui)


