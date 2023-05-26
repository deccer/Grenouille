#pragma once

#include <Grenouille/Format.hpp>

#include <cstdint>

struct InputElementDescriptor
{
    const char* semanticName;
    Format format;
    uint32_t inputSlot;
    uint32_t alignedByteOffset;
};