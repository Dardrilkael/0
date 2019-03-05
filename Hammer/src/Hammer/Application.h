#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"

namespace Hammer 
{
	class HM_API Application
	{
		bool m_Running = true;
	
	public:
		Application();
		~Application();
		void OnEvent(Event& e);
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
	};
	Application* CreateApplication();
}
