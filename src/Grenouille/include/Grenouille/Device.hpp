#pragma once

#include <memory>

class DeviceContext;
class InputLayout;
struct InputLayoutDescriptor;
class Swapchain;
struct SwapchainDescriptor;
class RenderTargetView;
struct RenderTargetViewDescriptor;
class Resource;
class Texture2D;
struct Texture2DDescriptor;

class Device
{
public:
    Device(const Device&) = delete;
    Device &operator=(const Device&) = delete;

    Device() = default;
    std::unique_ptr<InputLayout> CreateInputLayout(const InputLayoutDescriptor& inputLayoutDescriptor);
    std::unique_ptr<Swapchain> CreateSwapchain(const SwapchainDescriptor& swapchainDescriptor);

    std::unique_ptr<RenderTargetView> CreateRenderTargetView(Resource* resource, RenderTargetViewDescriptor* renderTargetViewDescriptor);
    std::unique_ptr<Texture2D> CreateTexture2D(const Texture2DDescriptor& textureDescriptor);
    std::shared_ptr<DeviceContext> GetImmediateDeviceContext();

private:
    std::shared_ptr<DeviceContext> _deviceContext;
};
