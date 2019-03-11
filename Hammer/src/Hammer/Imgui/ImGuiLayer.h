#pragma once
#include "Hammer/Layer.h"
#include "Hammer/Core.h"

#include "Hammer/Events/ApplicationEvent.h"
#include "Hammer/Events/KeyEvent.h"
#include "Hammer/Events/MouseEvent.h"

namespace Hammer {

	class HM_API ImGuiLayer : public Layer
	{
	public:
		void OnAttach();
		void OnDetach();
		ImGuiLayer();
		~ImGuiLayer();

		void OnUpdate();
		void OnEvent(Event& event);
	private:
		float m_Time = 0.0f ;
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);

	};

}