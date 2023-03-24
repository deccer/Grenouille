#pragma once

#include <Grenouille/Swapchain.hpp>
#include <Grenouille/DeviceContext.hpp>

#include <memory>

class Device
{
public:
    Device() = default;
    std::unique_ptr<Swapchain> CreateSwapchain(SwapchainDescriptor swapchainDescriptor);

    std::shared_ptr<DeviceContext> GetImmediateDeviceContext();

private:
    Device(const Device&);
    Device &operator=(const Device&);

    std::shared_ptr<DeviceContext> _deviceContext;
};
