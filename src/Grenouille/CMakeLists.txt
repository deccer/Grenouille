cmake_minimum_required(VERSION 3.14)
project(Grenouille)

add_subdirectory(lib)

set(sourceFiles
    Application.cpp
    BlendState.cpp
    Buffer.cpp
    ComputeShader.cpp
    DepthStencilState.cpp
    DepthStencilView.cpp
    Device.cpp
    DeviceContext.cpp
    InputLayout.cpp
    PixelShader.cpp
    RasterizerState.cpp
    RenderTargetView.cpp
    Resource.cpp
    SamplerState.cpp
    ShaderResourceView.cpp
    Swapchain.cpp
    UnorderedAccessView.cpp
    VertexShader.cpp
)

set(headerFiles
    include/Grenouille/Application.hpp
    include/Grenouille/ApplicationBuilder.hpp
)
add_library(Grenouille ${sourceFiles} ${headerFiles})

find_package(OpenGL REQUIRED)

add_compile_options(-Wall -Wextra -Werror)
target_include_directories(glfw PUBLIC include)
target_include_directories(glad PUBLIC include)
target_include_directories(imgui PUBLIC include)
target_include_directories(spdlog PUBLIC include)
target_include_directories(Grenouille PRIVATE include)

target_link_libraries(Grenouille PRIVATE glfw glad glm TracyClient spdlog imgui)


