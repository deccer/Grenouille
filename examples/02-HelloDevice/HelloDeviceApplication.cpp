#include "Grenouille/Application.hpp"
#define CGLTF_IMPLEMENTATION
#include <cgltf.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <HelloDevice/HelloDeviceApplication.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>

#include <glm/gtc/type_ptr.hpp>
#include <glm/mat4x4.hpp>

#include <spdlog/spdlog.h>

void HelloDeviceApplication::AfterCreatedUiContext()
{
}

void HelloDeviceApplication::BeforeDestroyUiContext()
{
}

bool HelloDeviceApplication::Initialize()
{
    if (!Application::Initialize())
    {
        return false;
    }

    return true;
}

bool HelloDeviceApplication::Load()
{
    if (!Application::Load())
    {
        spdlog::error("App: Unable to load");
        return false;
    }

    return true;
}

void HelloDeviceApplication::Update()
{
    if (IsKeyPressed(GLFW_KEY_ESCAPE))
    {
        Close();
    }
}

void HelloDeviceApplication::RenderScene()
{
}

void HelloDeviceApplication::RenderUI()
{
}