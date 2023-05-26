#pragma once

#include <Grenouille/Application.hpp>
#include <Grenouille/DepthStencilView.hpp>
#include <Grenouille/Device.hpp>
#include <Grenouille/DeviceContext.hpp>
#include <Grenouille/InputLayout.hpp>
#include <Grenouille/PixelShader.hpp>
#include <Grenouille/RenderTargetView.hpp>
#include <Grenouille/Swapchain.hpp>
#include <Grenouille/VertexShader.hpp>

#include <memory>
#include <glm/vec4.hpp>

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
        _clearColor = glm::vec4(0.3f, 0.5f, 0.7f, 1.0f);

        _simpleVertexShader = nullptr;
        _simplePixelShader = nullptr;

        _positionColorInputLayout = nullptr;
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

    std::unique_ptr<InputLayout> _positionColorInputLayout;
    std::unique_ptr<VertexShader> _simpleVertexShader;
    std::unique_ptr<PixelShader> _simplePixelShader;
    glm::vec4 _clearColor;
};