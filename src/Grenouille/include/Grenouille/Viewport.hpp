#pragma once

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

struct Viewport
{
public:
    Viewport(glm::vec4 viewRectangle, glm::vec2 minMaxDepth)
    {
        ViewRectangle = viewRectangle;
        MinMaxDepth = minMaxDepth;
    }

    glm::vec4 ViewRectangle;
    glm::vec2 MinMaxDepth;
};