#pragma once

#include <Grenouille/Resource.hpp>

class Device;
struct RenderTargetViewDescriptor;

class RenderTargetView
{
public:
    RenderTargetView(Device* device, Resource* resource, RenderTargetViewDescriptor* renderTargetViewDescriptor);
private:
    RenderTargetView(const RenderTargetView&) = delete;
    RenderTargetView &operator=(const RenderTargetView&) = delete;

    Device* _device = nullptr;
    Resource* _resource = nullptr;
    RenderTargetViewDescriptor* _renderTargetViewDescriptor = nullptr;
};