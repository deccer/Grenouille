#include <Grenouille/RenderTargetView.hpp>
#include <Grenouille/RenderTargetViewDescriptor.hpp>
#include <Grenouille/Texture2D.hpp>

#include <algorithm>
#include <cassert>

RenderTargetView::RenderTargetView(Device* device, Resource* resource, RenderTargetViewDescriptor* renderTargetViewDescriptor)
{
    assert(device != nullptr && "device must not be null");
    assert(resource != nullptr && "resource must not be null");

    _device = device;
    _resource = resource;
    _renderTargetViewDescriptor = renderTargetViewDescriptor;
}