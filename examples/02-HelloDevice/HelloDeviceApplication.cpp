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
    swapchainDescriptor.windowHandle = Application::GetWindowHandle();

    _swapchain = _device->CreateSwapchain(swapchainDescriptor);
    auto backBuffer = _swapchain->GetBuffer(0);

    _defaultRenderTargetView = _device->CreateRenderTargetView(backBuffer.get(), nullptr);

    return true;
}

bool HelloDeviceApplication::Load()
{
    if (!Application::Load())
    {
        spdlog::error("App: Unable to load");
        return false;
    }

    std::array<InputElementDescriptor, 2> inputElements {
        InputElementDescriptor
        { 
            .semanticName = "i_position", 
            .format = Format::R32G32B32Float, 
            .inputSlot = 0, 
            .alignedByteOffset = 0 
        },
        InputElementDescriptor
        { 
            .semanticName = "i_color", 
            .format = Format::R32G32B32Float, 
            .inputSlot = 0, 
            .alignedByteOffset = 12
        }};

    auto positionColorInputLayoutDescriptor = InputLayoutDescriptor 
    { 
        .elements = { inputElements }
    };
        
    _positionColorInputLayout = _device->CreateInputLayout(positionColorInputLayoutDescriptor);

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
    auto rtv = _defaultRenderTargetView.get();
    _deviceContext->ClearRenderTargetView(rtv, glm::value_ptr(_clearColor));
    _deviceContext->OMSetRenderTargets(1, &rtv, _defaultDepthStencilView.get());

    _deviceContext->IASetInputLayout(_positionColorInputLayout.get());
    _deviceContext->VSSetShader(_simpleVertexShader.get());
    _deviceContext->PSSetShader(_simplePixelShader.get());

    _deviceContext->Draw(3, 0);

    _swapchain->Present(0, PresentFlags::FlipSequential);
}

void HelloDeviceApplication::RenderUI()
{
}