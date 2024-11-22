#pragma once

#include "CIEngine/Core/Layer.h"

#include "CIEngine/Events/ApplicationEvent.h"
#include "CIEngine/Events/KeyEvent.h"
#include "CIEngine/Events/MouseEvent.h"

namespace CIEngine {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }
		
		void SetDarkThemeColors();

		uint32_t GetActiveWidgetID() const;
	private:
		bool m_BlockEvents = true;
	};

}
