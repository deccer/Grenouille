#pragma once

#include <Grenouille/Application.hpp>
#include <Grenouille/Device.hpp>
#include <Grenouille/DeviceContext.hpp>
#include <Grenouille/Swapchain.hpp>
#include <Grenouille/RenderTargetView.hpp>
#include <Grenouille/DepthStencilView.hpp>

#include <memory>

class HelloDeviceApplication final : public Application
{
public:
    HelloDeviceApplication(const std::string& title, int32_t width, int32_t height, float scaleFactor)
        : Application(title, width, height, scaleFactor)
    {
        _device = nullptr;
        _deviceContext = nullptr;
        _swapchain = nullptr;
        _defaultRenderTargetView = nullptr;
        _defaultDepthStencilView = nullptr;
        _clearColor = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    }
protected:
    void AfterCreatedUiContext() override;
    void BeforeDestroyUiContext() override;
    bool Initialize() override;
    bool Load() override;
    void RenderScene() override;
    void RenderUI() override;
    void Update() override;

private:
    std::unique_ptr<Device> _device;
    std::shared_ptr<DeviceContext> _deviceContext;
    std::unique_ptr<Swapchain> _swapchain;

    std::unique_ptr<RenderTargetView> _defaultRenderTargetView;
    std::unique_ptr<DepthStencilView> _defaultDepthStencilView;
    glm::vec4 _clearColor;
};