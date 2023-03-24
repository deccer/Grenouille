#include <Grenouille/Device.hpp>

std::unique_ptr<Swapchain> Device::CreateSwapchain(SwapchainDescriptor swapchainDescriptor)
{
    return std::make_unique<Swapchain>(this, swapchainDescriptor);
}

std::shared_ptr<DeviceContext> Device::GetImmediateDeviceContext()
{
    return _deviceContext;
}