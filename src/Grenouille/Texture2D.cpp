#include <glad/glad.h>

#include <Grenouille/Texture2D.hpp>
#include <Grenouille/Texture2DDescriptor.hpp>

Texture2D::Texture2D(Device* device, const Texture2DDescriptor& textureDescriptor)
{
    glCreateTextures(GL_TEXTURE_2D, 1, &_id);
}

void Texture2D::SetDebugName(const std::string& debugName)
{
    glObjectLabel(GL_TEXTURE_2D, _id, debugName.size(), debugName.data());
}