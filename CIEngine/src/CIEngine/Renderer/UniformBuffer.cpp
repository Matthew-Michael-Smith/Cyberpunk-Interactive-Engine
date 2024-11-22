#include "ciepch.h"
#include "UniformBuffer.h"

#include "CIEngine/Renderer/Renderer.h"
#include "Platform/Vulkan/VulkanUniformBuffer.h"

namespace Hazel {

	Ref<UniformBuffer> UniformBuffer::Create(uint32_t size, uint32_t binding)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    CIE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::Vulkan:  return CreateRef<VulkanUniformBuffer>(size, binding);
		}

		CIE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
