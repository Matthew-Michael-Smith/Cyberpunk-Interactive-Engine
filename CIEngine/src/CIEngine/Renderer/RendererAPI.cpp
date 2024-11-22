#include "ciepch.h"
#include "Hazel/Renderer/RendererAPI.h"

#include "Platform/Vulkan/VulkanRendererAPI.h"

namespace CIEngine {

	RendererAPI::API RendererAPI::s_API = RendererAPI::API::Vulkan;

	Scope<RendererAPI> RendererAPI::Create()
	{
		switch (s_API)
		{
			case RendererAPI::API::None:    CIE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::Vulkan:  return CreateScope<VulkanRendererAPI>();
		}

		CIE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}