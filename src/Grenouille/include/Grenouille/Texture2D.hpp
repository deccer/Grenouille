#pragma once

#include <Grenouille/Resource.hpp>
#include <cstdint>

class Device;
struct Texture2DDescriptor;

class Texture2D : public Resource
{
public:
    Texture2D(const Texture2D& other) = delete;
    Texture2D(Texture2D&& other) = delete;

    Texture2D(Device* device, const Texture2DDescriptor& textureDescriptor);

    void SetDebugName(const std::string& debugName) override;
private:
    uint32_t _id = 0u;
};