#include "ciepch.h"
#include "CIEngine/Renderer/VertexArray.h"

#include "CIEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace CIEngine {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    CIE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::Vulkan:  return CreateRef<VulkanVertexArray>();
		}

		CIE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}