#pragma once

#include "Core.h"

namespace CIEngine {
	class CIENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	CIEngine::Application* CreateApplication();

}