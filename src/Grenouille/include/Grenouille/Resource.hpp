#pragma once

#include <Grenouille/DeviceChild.hpp>

class Resource : public DeviceChild
{
public:
    Resource();
    Resource(const Resource& other) = delete;
    Resource(Resource&& other) = delete;

    virtual ~Resource() = default;
private:
};