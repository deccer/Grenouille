#include <Grenouille/Device.hpp>
#include <Grenouille/InputLayout.hpp>
#include <Grenouille/InputLayoutDescriptor.hpp>
#include <Grenouille/RenderTargetView.hpp>
#include <Grenouille/RenderTargetViewDescriptor.hpp>
#include <Grenouille/Resource.hpp>
#include <Grenouille/Swapchain.hpp>
#include <Grenouille/SwapchainDescriptor.hpp>
#include <Grenouille/Texture2D.hpp>
#include <Grenouille/Texture2DDescriptor.hpp>

std::unique_ptr<InputLayout> Device::CreateInputLayout(const InputLayoutDescriptor& inputLayoutDescriptor)
{
    return std::make_unique<InputLayout>(inputLayoutDescriptor);
}

std::unique_ptr<RenderTargetView> Device::CreateRenderTargetView(Resource* resource, RenderTargetViewDescriptor* renderTargetViewDescriptor)
{
    return std::make_unique<RenderTargetView>(this, resource, renderTargetViewDescriptor);
}

std::unique_ptr<Texture2D> Device::CreateTexture2D(const Texture2DDescriptor& textureDescriptor)
{
    return std::make_unique<Texture2D>(this, textureDescriptor);
}

std::unique_ptr<Swapchain> Device::CreateSwapchain(const SwapchainDescriptor& swapchainDescriptor)
{
    return std::make_unique<Swapchain>(this, swapchainDescriptor);
}

std::shared_ptr<DeviceContext> Device::GetImmediateDeviceContext()
{
    return _deviceContext;
}