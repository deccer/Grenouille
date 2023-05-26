#pragma once

#include <cstdint>

#include <Grenouille/Format.hpp>
#include <Grenouille/Usage.hpp>
#include <Grenouille/BindFlags.hpp>
#include <Grenouille/CpuAccessFlag.hpp>

struct Texture2DDescriptor
{
    uint32_t width;
    uint32_t height;
    uint32_t mipLevels;
    uint32_t arraySize;
    Format format;
    Usage usage;
    uint32_t cpuAccessFlags;
    uint32_t bindFlags;
};