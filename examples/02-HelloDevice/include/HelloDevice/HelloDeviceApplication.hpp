#pragma once

#include <Grenouille/Application.hpp>

class HelloDeviceApplication final : public Application
{
public:
    HelloDeviceApplication(const std::string& title, int32_t width, int32_t height, float scaleFactor)
        : Application(title, width, height, scaleFactor)
    {
    }
protected:
    void AfterCreatedUiContext() override;
    void BeforeDestroyUiContext() override;
    bool Initialize() override;
    bool Load() override;
    void RenderScene() override;
    void RenderUI() override;
    void Update() override;
};