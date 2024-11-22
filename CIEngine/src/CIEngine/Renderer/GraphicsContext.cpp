#include "ciepch.h"
#include "CIEngine/Renderer/GraphicsContext.h"

#include "CIEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace CIEngine {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    CIE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		CIE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}