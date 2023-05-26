#pragma once

#include <cstdint>
#include <map>

class DepthStencilView;
class RenderTargetView;
class UnorderedAccessView;
class ShaderResourceView;

class Resource;
class Buffer;

class BlendState;
class DepthStencilState;
class RasterizerState;
class SamplerState;

enum class Format;
enum class PrimitiveTopology;
struct Viewport;

class InputLayout;
struct InputLayoutDescriptor;

class ComputeShader;
class VertexShader;
class PixelShader;

class DeviceContext
{
public:
    void ClearDepthStencilView(DepthStencilView* depthStencilView, uint32_t clearFlags, float depth, uint8_t stencil);
    void ClearRenderTargetView(RenderTargetView* renderTargetView, float clearColor[4]);
    void ClearState();
    void ClearUnorderedAccessViewFloat(UnorderedAccessView* unorderedAccessView, float clearValue[4]);
    void ClearUnorderedAccessViewUint(UnorderedAccessView* unorderedAccessView, uint32_t clearValue[4]);

    void CopyResource(Resource* destination, Resource* source);

    void CSSetConstantBuffers(uint32_t startSlot, uint32_t numBuffers, const Buffer** constantBuffers);
    void CSSetSamplers(uint32_t startSlot, uint32_t numSamplers, SamplerState** samplers);
    void CSSetShader(ComputeShader* computeShader);
    void CSSetShaderResourceViews(uint32_t startSlot, uint32_t numShaderResourceViews, ShaderResourceView** shaderResourceViews);

    void Dispatch(uint32_t threadGroupCountX, uint32_t threadGroupCountY, uint32_t threadGroupCountZ);
    void DispatchIndirect(Buffer* indirectBuffer, uint32_t indirectElementOffsetInBytes);
    void Draw(uint32_t vertexCount, uint32_t vertexOffset);
    void DrawIndexed(uint32_t indexCount, uint32_t startIndex, int32_t baseVertex);
    void DrawIndexedInstanced(uint32_t indexCountPerInstance, uint32_t instanceCount, uint32_t startIndex, int32_t baseVertex, uint32_t baseInstance);
    void DrawIndexedInstancedIndirect(Buffer* indirectBuffer, uint32_t indirectElementOffsetInBytes);

    void GenerateMips(ShaderResourceView* shaderResourceView);

    void IASetIndexBuffer(Buffer* indexBuffer, Format format, uint32_t offset);
    void IASetInputLayout(InputLayout* inputLayout);
    void IASetPrimitiveTopology(PrimitiveTopology primitiveTopology);
    void IASetVertexBuffer(uint32_t startSlot, uint32_t numBuffers, Buffer** vertexBuffer, uint32_t* strides, uint32_t* offsets);

    void OMSetBlendState(BlendState* blendState, float blendFactor[4], uint32_t sampleMask);
    void OMSetDepthStencilState(DepthStencilState* depthStencilState, uint32_t stencilReference);
    void OMSetRenderTargets(uint32_t numRenderTargetViews, RenderTargetView** renderTargetViews, DepthStencilView* depthStencilView);
    void OMSetRenderTargetsAndUnorderedAccessViews(uint32_t numRenderTargetViews, RenderTargetView**, DepthStencilView* depthStencilView, uint32_t unorderedAccessViewStartSlot, uint32_t numUnorderedAccessViews, UnorderedAccessView** unorderedAccessViews, uint32_t* unorderedAccessViewInitialCounts);

    void PSSetConstantBuffers(uint32_t startSlot, uint32_t numBuffers, const Buffer** constantBuffers);
    void PSSetSamplers(uint32_t startSlot, uint32_t numSamplers, SamplerState** samplers);
    void PSSetShader(PixelShader* pixelShader);
    void PSSetShaderResourceViews(uint32_t startSlot, uint32_t numShaderResourceViews, ShaderResourceView** shaderResourceViews);

    void RSSetState(RasterizerState* rasterizerState);
    void RSSetViewports(uint32_t numViewports, Viewport* viewports);

    void VSSetConstantBuffers(uint32_t startSlot, uint32_t numBuffers, const Buffer** constantBuffers);
    void VSSetSamplers(uint32_t startSlot, uint32_t numSamplers, SamplerState** samplers);
    void VSSetShader(VertexShader* vertexShader);
    void VSSetShaderResourceViews(uint32_t startSlot, uint32_t numShaderResourceViews, ShaderResourceView** shaderResourceViews);

private:
    std::map<InputLayoutDescriptor, InputLayout*> _cachedInputLayouts = {};
    PrimitiveTopology _currentPrimitiveTopology;
};