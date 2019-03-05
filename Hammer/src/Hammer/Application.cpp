#include "Application.h"
#include "Log.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Events/ApplicationEvent.h"
//#include "Platform/Windows/WindowsWindow.h"
#include "glad/glad.h"

namespace Hammer{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
Application::Application()
{
	m_Window = std::unique_ptr<Window>(Window::Create());
	m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	
}


Application::~Application()
{
}

void Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
	glClearColor(0.5f, 0.4f, 0.9f, 1.0f);
	HM_CORE_INFO(e);
}

void Application::Run()
{
	
	while (m_Running)
	{
		m_Window->OnUpDate();
	}
}

bool Application::OnWindowClose(WindowCloseEvent & e)
{
	m_Running = false;
	return true;
}

}
