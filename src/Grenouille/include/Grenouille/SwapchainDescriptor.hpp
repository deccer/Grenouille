#pragma once

#include <Grenouille/Format.hpp>
#include <Grenouille/SwapchainFlags.hpp>
#include <Grenouille/ModeDescriptor.hpp>
#include <Grenouille/SampleDescriptor.hpp>
#include <Grenouille/BufferUsage.hpp>
#include <Grenouille/SwapEffect.hpp>

#include <cstdint>

struct GLFWwindow;

struct SwapchainDescriptor
{
    ModeDescriptor modeDescriptor;
    SampleDescriptor sampleDescriptor;
    BufferUsage bufferUsage;
    uint32_t bufferCount;
    GLFWwindow* windowHandle;
    bool isWindowed;
    SwapEffect swapEffect;
    SwapchainFlags flags;
};