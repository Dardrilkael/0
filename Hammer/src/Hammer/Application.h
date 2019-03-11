 #pragma once

#include "Core.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "Hammer/LayerStack.h"
#include "Events/Event.h"

namespace Hammer {
	class HM_API Application
	{

	public:
		Application();
		~Application();
		void  OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		void Run();
		
		inline static Application& Get() {return *s_Instance;}
		inline Window& GetWindow()const { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};
	Application* CreateApplication();
}
