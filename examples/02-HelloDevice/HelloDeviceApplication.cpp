#include <HelloDevice/HelloDeviceApplication.hpp>

#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
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
        spdlog::error("App: Unable to initialize");
        return false;
    }

    _device = std::make_unique<Device>();
    _deviceContext = _device->GetImmediateDeviceContext();

    SwapchainDescriptor swapchainDescriptor;
    swapchainDescriptor.WindowHandle = Application::GetWindowHandle();

    _swapchain = _device->CreateSwapchain(swapchainDescriptor);

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
#ifdef _DEBUG
    _deviceContext->ClearState();
#endif
    auto* rtv = _defaultRenderTargetView.get();
    _deviceContext->ClearRenderTargetView(rtv, glm::value_ptr(_clearColor));
    _deviceContext->OMSetRenderTargets(1, &rtv, _defaultDepthStencilView.get());

    _swapchain->Present(0, PresentFlags::FlipSequential);
}

void HelloDeviceApplication::RenderUI()
{
}