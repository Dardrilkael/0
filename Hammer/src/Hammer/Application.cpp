#include "hmpch.h"
#include "Application.h"
#include "Log.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Events/ApplicationEvent.h"
#include "Input.h"
#include "glad/glad.h"
#include <iostream>
namespace Hammer {
//#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
{
		HM_CORE_TRACER
		//HM_CORE_ASSERT(s_Instance,"Application already exits");
		s_Instance = this;

	m_Window = std::unique_ptr<Window>(Window::Create());
	m_Window->SetEventCallback(HM_BIND_EVENT_FN(Application::OnEvent));
}


Application::~Application()
{
	HM_CORE_TRACER
}

void Application::PushLayer(Layer * layer)
{
	HM_CORE_TRACER
	m_LayerStack.PushLayer(layer);
	layer->OnAttach();
}

void Application::PushOverlay(Layer * layer)
{
	HM_CORE_TRACER
	m_LayerStack.PushOverlay(layer);
	layer->OnAttach();
}

void Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(HM_BIND_EVENT_FN(Application::OnWindowClose));
	

	for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
	{
		(*--it)->OnEvent(e);
		if (e.Handled)
			break;
	}
	
}



void Application::Run()
{
	HM_CORE_TRACER
	while (m_Running)
	{
		glClearColor(0.5f, 0.4f, 0.9f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		for (Layer* layer : m_LayerStack)
			layer->OnUpdate();

		m_Window->OnUpDate();
	}
}

bool Application::OnWindowClose(WindowCloseEvent & e)
{
	m_Running = false;
	return true;
}

}
