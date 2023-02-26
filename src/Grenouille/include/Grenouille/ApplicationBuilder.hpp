#pragma once

#include <Grenouille/Application.hpp>

#include <string>

template <typename TApplication>
class ApplicationBuilder
{
public:
    ApplicationBuilder() noexcept
    {
        _width = 1920;
        _height = 1080;
        _scaleFactor = 1.0f;
        _title = "Application";
    }

    ApplicationBuilder& WithTitle(const std::string& title)
    {
        _title = title;
        return *this;
    }

    ApplicationBuilder& WithSize(int32_t width, int32_t height)
    {
        _width = width;
        _height = height;
        return *this;
    }

    ApplicationBuilder& ScaleFramebuffer(float scaleFactor)
    {
        _scaleFactor = scaleFactor;
        return *this;
    }

    TApplication Build()
    {
        TApplication application(_title, _width, _height, _scaleFactor);
        return application;
    }

private:
    std::string _title;
    int32_t _width;
    int32_t _height;
    float _scaleFactor;
};