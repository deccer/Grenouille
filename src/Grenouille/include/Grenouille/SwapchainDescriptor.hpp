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
    ModeDescriptor ModeDescriptor;
    SampleDescriptor SampleDescriptor;
    BufferUsage BufferUsage;
    uint32_t BufferCount;
    GLFWwindow* WindowHandle;
    bool IsWindowed;
    SwapEffect SwapEffect;
    SwapchainFlags Flags;
};