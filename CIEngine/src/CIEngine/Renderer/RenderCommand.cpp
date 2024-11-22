#include "ciepch.h"
#include "CIEngine/Renderer/RenderCommand.h"

namespace CIEngine {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}