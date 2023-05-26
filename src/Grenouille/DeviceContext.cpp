#include <Grenouille/DeviceContext.hpp>
#include <Grenouille/DepthStencilView.hpp>
#include <Grenouille/RenderTargetView.hpp>
#include <Grenouille/ShaderResourceView.hpp>
#include <Grenouille/UnorderedAccessView.hpp>
#include <Grenouille/Resource.hpp>
#include <Grenouille/Buffer.hpp>
#include <Grenouille/SamplerState.hpp>
#include <Grenouille/ComputeShader.hpp>
#include <Grenouille/PixelShader.hpp>
#include <Grenouille/VertexShader.hpp>
#include <Grenouille/InputLayout.hpp>
#include <Grenouille/BlendState.hpp>
#include <Grenouille/DepthStencilState.hpp>
#include <Grenouille/RasterizerState.hpp>

void DeviceContext::ClearDepthStencilView(DepthStencilView* depthStencilView, uint32_t clearFlags, float depth, uint8_t stencil)
{

}

void DeviceContext::ClearRenderTargetView(RenderTargetView* renderTargetView, float clearColor[4])
{

}

void DeviceContext::ClearState()
{

}

void DeviceContext::ClearUnorderedAccessViewFloat(UnorderedAccessView* unorderedAccessView, float clearValue[4])
{

}

void DeviceContext::ClearUnorderedAccessViewUint(UnorderedAccessView* unorderedAccessView, uint32_t clearValue[4])
{

}

void DeviceContext::CopyResource(Resource* destination, Resource* source)
{

}

void DeviceContext::CSSetConstantBuffers(uint32_t startSlot, uint32_t numBuffers, const Buffer** constantBuffers)
{

}

void DeviceContext::CSSetSamplers(uint32_t startSlot, uint32_t numSamplers, SamplerState** samplers)
{

}

void DeviceContext::CSSetShader(ComputeShader* computeShader)
{

}

void DeviceContext::CSSetShaderResourceViews(uint32_t startSlot, uint32_t numShaderResourceViews, ShaderResourceView** shaderResourceViews)
{

}

void DeviceContext::Dispatch(uint32_t threadGroupCountX, uint32_t threadGroupCountY, uint32_t threadGroupCountZ)
{

}

void DeviceContext::DispatchIndirect(Buffer* indirectBuffer, uint32_t indirectElementOffsetInBytes)
{

}

void DeviceContext::Draw(uint32_t vertexCount, uint32_t vertexOffset)
{

}

void DeviceContext::DrawIndexed(uint32_t indexCount, uint32_t startIndex, int32_t baseVertex)
{

}

void DeviceContext::DrawIndexedInstanced(uint32_t indexCountPerInstance, uint32_t instanceCount, uint32_t startIndex, int32_t baseVertex, uint32_t baseInstance)
{

}

void DeviceContext::DrawIndexedInstancedIndirect(Buffer* indirectBuffer, uint32_t indirectElementOffsetInBytes)
{

}

void DeviceContext::GenerateMips(ShaderResourceView* shaderResourceView)
{

}

void DeviceContext::IASetIndexBuffer(Buffer* indexBuffer, Format format, uint32_t offset)
{

}

void DeviceContext::IASetInputLayout(InputLayout* inputLayout)
{

}

void DeviceContext::IASetPrimitiveTopology(PrimitiveTopology primitiveTopology)
{
    _currentPrimitiveTopology = primitiveTopology;
}

void DeviceContext::IASetVertexBuffer(uint32_t startSlot, uint32_t numBuffers, Buffer** vertexBuffer, uint32_t* strides, uint32_t* offsets)
{

}

void DeviceContext::OMSetBlendState(
    BlendState* blendState,
    float blendFactor[4],
    uint32_t sampleMask)
{

}

void DeviceContext::OMSetDepthStencilState(
    DepthStencilState* depthStencilState,
    uint32_t stencilReference)
{

}

void DeviceContext::OMSetRenderTargets(
    uint32_t numRenderTargetViews,
    RenderTargetView** renderTargetViews,
    DepthStencilView* depthStencilView)
{

}

void DeviceContext::OMSetRenderTargetsAndUnorderedAccessViews(
    uint32_t numRenderTargetViews,
    RenderTargetView** renderTargetViews,
    DepthStencilView* depthStencilView,
    uint32_t unorderedAccessViewStartSlot,
    uint32_t numUnorderedAccessViews,
    UnorderedAccessView** unorderedAccessViews,
    uint32_t* unorderedAccessViewInitialCounts)
{

}

void DeviceContext::PSSetConstantBuffers(
    uint32_t startSlot,
    uint32_t numBuffers,
    const Buffer** constantBuffers)
{

}

void DeviceContext::PSSetSamplers(
    uint32_t startSlot,
    uint32_t numSamplers,
    SamplerState** samplers)
{

}

void DeviceContext::PSSetShader(PixelShader* pixelShader)
{

}

void DeviceContext::PSSetShaderResourceViews(
    uint32_t startSlot,
    uint32_t numShaderResourceViews,
    ShaderResourceView** shaderResourceViews)
{

}

void DeviceContext::RSSetState(RasterizerState* rasterizerState)
{

}

void DeviceContext::RSSetViewports(uint32_t numViewports, Viewport* viewports)
{

}

void DeviceContext::VSSetConstantBuffers(uint32_t startSlot, uint32_t numBuffers, const Buffer** constantBuffers)
{

}

void DeviceContext::VSSetSamplers(uint32_t startSlot, uint32_t numSamplers, SamplerState** samplers)
{

}

void DeviceContext::VSSetShader(VertexShader* vertexShader)
{

}

void DeviceContext::VSSetShaderResourceViews(uint32_t startSlot, uint32_t numShaderResourceViews, ShaderResourceView** shaderResourceViews)
{

}