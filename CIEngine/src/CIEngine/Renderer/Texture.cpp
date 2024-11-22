#include "ciepch.h"
#include "CIEngine/Renderer/Texture.h"

#include "CIEngine/Renderer/Renderer.h"
#include "Platform/Vulkan/VulkanTexture.h"

namespace CIEngine {

	Ref<Texture2D> Texture2D::Create(const TextureSpecification& specification)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    CIE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::Vulkan:  return CreateRef<VulkanTexture2D>(specification);
		}

		CIE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::Vulkan:  return CreateRef<VulkanTexture2D>(path);
		}

		CIE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
