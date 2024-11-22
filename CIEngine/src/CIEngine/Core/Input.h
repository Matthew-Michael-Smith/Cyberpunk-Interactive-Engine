#pragma once

#include "CIEngine/Core/KeyCodes.h"
#include "CIEngine/Core/MouseCodes.h"

#include <glm/glm.hpp>

namespace CIEngine {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
