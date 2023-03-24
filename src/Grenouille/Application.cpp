#include <Grenouille/Application.hpp>

#include <spdlog/spdlog.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>

#include <tracy/Tracy.hpp>
#include <tracy/TracyOpenGL.hpp>

#include <iostream>
#include <string>

Application::Application(const std::string& title, int32_t width, int32_t height, float scaleFactor) noexcept
{
    _title = title;
    _width = width;
    _height = height;
    _scaleFactor = scaleFactor;
}

void Application::Run()
{
    FrameMarkStart("App Run");
    if (!Initialize())
    {
        return;
    }

    spdlog::info("App: Initialized");

    if (!Load())
    {
        return;
    }

    spdlog::info("App: Loaded");

    while (!glfwWindowShouldClose(_windowHandle))
    {
        glfwPollEvents();
        Update();
        Render();
    }

    spdlog::info("App: Unloading");

    Unload();

    spdlog::info("App: Unloaded");
    FrameMarkEnd("App Run");
}

void Application::Close()
{
    glfwSetWindowShouldClose(_windowHandle, 1);
}

bool Application::IsKeyPressed(int32_t key)
{
    return glfwGetKey(_windowHandle, key) == GLFW_PRESS;
}

bool Application::Initialize()
{
    if (!glfwInit())
    {
        spdlog::error("Glfw: Unable to initialize");
        return false;
    }

    glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);

    const auto primaryMonitor = glfwGetPrimaryMonitor();
    const auto primaryMonitorVideoMode = glfwGetVideoMode(primaryMonitor);

    const auto windowWidth = _width;
    const auto windowHeight = _height;

    _windowHandle = glfwCreateWindow(windowWidth, windowHeight, _title.data(), nullptr, nullptr);
    if (_windowHandle == nullptr)
    {
        spdlog::error("Glfw: Unable to create window");
        glfwTerminate();
        return false;
    }

    const auto screenWidth = primaryMonitorVideoMode->width;
    const auto screenHeight = primaryMonitorVideoMode->height;
    glfwSetWindowPos(_windowHandle, screenWidth / 2 - windowWidth / 2, screenHeight / 2 - windowHeight / 2);

    glfwMakeContextCurrent(_windowHandle);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    ImGui::CreateContext();
    AfterCreatedUiContext();
    ImGui_ImplGlfw_InitForOpenGL(_windowHandle, true);
    ImGui_ImplOpenGL3_Init();
    ImGui::StyleColorsDark();

    return true;
}

bool Application::Load()
{
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEPTH_TEST);
    glDebugMessageCallback([](GLenum source,
                              GLenum type,
                              GLuint,
                              GLenum severity,
                              GLsizei,
                              const GLchar* message,
                              const void*)
    {
        if (type == GL_DEBUG_TYPE_ERROR)
        {
            spdlog::error("GL CALLBACK: type = {}, severity = error, message = {}\n", type, message);
        }
    }, nullptr);
    glClearColor(0.7f, 0.5f, 0.2f, 1.0f);

    glfwSwapInterval(1);

    return true;
}

void Application::Unload()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    BeforeDestroyUiContext();
    ImGui::DestroyContext();

    glfwTerminate();
}

void Application::Render()
{
    ZoneScopedC(tracy::Color::Red2);

    RenderScene();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    {
        RenderUI();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        ImGui::EndFrame();
    }

    glfwSwapBuffers(_windowHandle);
}

void Application::RenderScene()
{
}

void Application::RenderUI()
{
}

void Application::Update()
{
}

void Application::AfterCreatedUiContext()
{
}

void Application::BeforeDestroyUiContext()
{
}

GLFWwindow* Application::GetWindowHandle()
{
    return _windowHandle;
}