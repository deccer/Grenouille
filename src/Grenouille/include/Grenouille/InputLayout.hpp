#pragma once

#include <Grenouille/InputLayoutDescriptor.hpp>

class InputLayout
{
public:
    InputLayout(InputLayoutDescriptor inputLayoutDescriptor);

private:
    InputLayout(const InputLayout&);
    InputLayout &operator=(const InputLayout&);

    InputLayoutDescriptor _inputLayoutDescripor;
};