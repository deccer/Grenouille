#pragma once

#include <Grenouille/Format.hpp>
#include <Grenouille/PresentFlags.hpp>
#include <Grenouille/SwapchainFlags.hpp>
#include <Grenouille/SwapchainDescriptor.hpp>

#include <cstdint>
#include <memory>

class Device;
class Resource;

class Swapchain
{
public:
    Swapchain(Device* device, SwapchainDescriptor swapchainDescriptor);

    std::shared_ptr<Resource> GetBuffer(uint32_t bufferIndex);

    void Present(uint32_t syncInterval, PresentFlags presentFlags);
    void ResizeBuffers(uint32_t bufferCount, uint32_t width, uint32_t height, Format format, SwapchainFlags swapchainFlags);

private:
    Device* _device = nullptr;
    SwapchainDescriptor _swapchainDescriptor = {};
    uint32_t _syncInterval = 0;

    uint32_t _defaultFramebuffer = -1;
    uint32_t _defaultColorAttachment0 = -1;
};