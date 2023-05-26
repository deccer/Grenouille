#pragma once

namespace BindFlags
{
    enum UnderlyingType
    {
        VertexBuffer = 0,
        IndexBuffer = 1,
        ConstantBuffer = 2,
        ShaderResource = 4,
        RenderTarget = 8,
        DepthStencil = 16,
        UnorderedAccess = 32,
    };
}