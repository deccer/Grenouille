#include <GLFW/glfw3.h>

#include <Grenouille/Device.hpp>
#include <Grenouille/Swapchain.hpp>
#include <Grenouille/SwapchainDescriptor.hpp>
#include <Grenouille/Texture2D.hpp>
#include <Grenouille/Texture2DDescriptor.hpp>

Swapchain::Swapchain(Device* device, SwapchainDescriptor swapchainDescriptor)
{
    _swapchainDescriptor = swapchainDescriptor;
    _device = device;
}

std::shared_ptr<Resource> Swapchain::GetBuffer(uint32_t bufferIndex)
{
    auto textureDescriptor = Texture2DDescriptor
    {
        .width = _swapchainDescriptor.modeDescriptor.width,
        .height = _swapchainDescriptor.modeDescriptor.height,
        .mipLevels = 1,
        .arraySize = 0,
        .format = _swapchainDescriptor.modeDescriptor.format,
        .usage = Usage::Immutable,
        .cpuAccessFlags = static_cast<uint32_t>(CpuAccessFlag::Read | CpuAccessFlag::Write),
        .bindFlags = static_cast<uint32_t>(BindFlags::RenderTarget | BindFlags::ShaderResource)
    };
    return _device->CreateTexture2D(textureDescriptor);
}

void Swapchain::Present(uint32_t syncInterval, PresentFlags presentFlags)
{
    if (_syncInterval != syncInterval)
    {
        _syncInterval = syncInterval;
        glfwSwapInterval(_syncInterval);
    }
    glfwSwapBuffers(_swapchainDescriptor.windowHandle);
}

void Swapchain::ResizeBuffers(uint32_t bufferCount, uint32_t width, uint32_t height, Format format, SwapchainFlags swapchainFlags)
{

}