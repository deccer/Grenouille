#pragma once

#include <Grenouille/Format.hpp>
#include <Grenouille/Rational.hpp>
#include <Grenouille/ScanlineOrder.hpp>
#include <Grenouille/ModeScaling.hpp>

struct ModeDescriptor
{
    uint32_t width;
    uint32_t height;
    Rational refreshRate;
    Format format;
    ScanlineOrder scanlineOrder;
    ModeScaling modeScaling;
};