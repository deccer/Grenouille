#pragma once

#include <Grenouille/InputElementDescriptor.hpp>

#include <span>

struct InputLayoutDescriptor
{
    std::span<InputElementDescriptor> elements;
};
