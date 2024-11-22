#include "ciepch.h"
#include "CIEngine/Core/Window.h"

#ifdef CIE_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace CIEngine
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
	#ifdef CIE_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
	#else
		CIE_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}

}