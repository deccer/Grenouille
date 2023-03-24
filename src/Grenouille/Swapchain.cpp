#include "GLFW/glfw3.h"
#include <Grenouille/Swapchain.hpp>

Swapchain::Swapchain(Device* device, SwapchainDescriptor swapchainDescriptor)
{
    _swapchainDescriptor = swapchainDescriptor;
}

void Swapchain::Present(uint32_t syncInterval, PresentFlags presentFlags)
{
    if (_syncInterval != syncInterval)
    {
        _syncInterval = syncInterval;
        glfwSwapInterval(_syncInterval);
    }
    glfwSwapBuffers(_swapchainDescriptor.WindowHandle);
}

void Swapchain::ResizeBuffers(uint32_t bufferCount, uint32_t width, uint32_t height, Format format, SwapchainFlags swapchainFlags)
{

}