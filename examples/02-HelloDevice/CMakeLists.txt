cmake_minimum_required(VERSION 3.14)
project(HelloDevice)

target_include_directories(imgui PUBLIC include)
target_include_directories(spdlog PUBLIC include)

set(sourceFiles
    Main.cpp
    HelloDeviceApplication.cpp
)
set(headerFiles
    include/HelloDevice/HelloDeviceApplication.hpp
)
add_executable(HelloDevice ${sourceFiles} ${headerFiles})
add_dependencies(HelloDevice copy_data)

target_compile_options(HelloDevice PUBLIC -Wall -Wextra -Werror)

target_include_directories(HelloDevice PRIVATE include)
target_include_directories(Grenouille PUBLIC include)
target_link_libraries(HelloDevice PRIVATE glad glfw imgui glm cgltf stb_image spdlog Grenouille)
