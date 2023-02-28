cmake_minimum_required(VERSION 3.14)
project(HelloWindow)

target_include_directories(imgui PUBLIC include)
target_include_directories(spdlog PUBLIC include)

set(sourceFiles
    Main.cpp
    HelloWindowApplication.cpp
)
set(headerFiles
    include/HelloWindow/HelloWindowApplication.hpp
)
add_executable(HelloWindow ${sourceFiles} ${headerFiles})
add_dependencies(HelloWindow copy_data)

add_compile_options(-Wall -Wextra -Werror)

target_include_directories(HelloWindow PRIVATE include)
target_include_directories(Grenouille PUBLIC include)
target_link_libraries(HelloWindow PRIVATE glad glfw imgui glm cgltf stb_image spdlog Grenouille)
