#pragma once

#include <string>

class DeviceChild
{
public:
    DeviceChild() = default;
    DeviceChild(const DeviceChild& other) = delete;
    DeviceChild(DeviceChild&& other) = delete;

    virtual ~DeviceChild() = default;
    virtual void SetDebugName(const std::string& debugName) = 0;
private:
};