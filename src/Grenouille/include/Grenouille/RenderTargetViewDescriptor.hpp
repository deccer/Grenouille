#pragma once

#include <Grenouille/Format.hpp>
#include <Grenouille/RenderTargetViewDimension.hpp>

struct RenderTargetViewDescriptor
{
    Format format;
    RenderTargetViewDimension dimension;
};