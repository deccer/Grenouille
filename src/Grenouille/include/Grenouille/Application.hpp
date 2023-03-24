#pragma once

#include <cstdint>
#include <string>

struct GLFWwindow;

class Application
{
public:
    Application(const std::string& title, int32_t width, int32_t height, float scaleFactor) noexcept;
    virtual ~Application() {}
    void Run();

protected:

    void Close();
    bool IsKeyPressed(int32_t key);
    virtual void AfterCreatedUiContext();
    virtual void BeforeDestroyUiContext();
    virtual bool Initialize();
    virtual bool Load();
    virtual void Unload();
    virtual void RenderScene();
    virtual void RenderUI();
    virtual void Update();

    GLFWwindow* GetWindowHandle();

private:
    GLFWwindow* _windowHandle = nullptr;
    std::string _title;
    int32_t _width;
    int32_t _height;
    float _scaleFactor;

    void Render();
};