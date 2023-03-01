#pragma once

#include <Grenouille/Format.hpp>
#include <Grenouille/Rational.hpp>
#include <Grenouille/ScanlineOrder.hpp>
#include <Grenouille/ModeScaling.hpp>

struct ModeDescriptor
{
    uint32_t Width;
    uint32_t Height;
    Rational RefreshRate;
    Format Format;
    ScanlineOrder ScanlineOrder;
    ModeScaling ModeScaling;
};