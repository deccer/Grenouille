#pragma once

#pragma once

#include <Grenouille/Format.hpp>
#include <Grenouille/PresentFlags.hpp>
#include <Grenouille/SwapchainDescriptor.hpp>
#include <Grenouille/SwapchainFlags.hpp>

#include <cstdint>

class Device;

class Swapchain
{
public:
    Swapchain(Device* device, SwapchainDescriptor swapchainDescriptor);

    void Present(uint32_t syncInterval, PresentFlags presentFlags);
    void ResizeBuffers(uint32_t bufferCount, uint32_t width, uint32_t height, Format format, SwapchainFlags swapchainFlags);
};