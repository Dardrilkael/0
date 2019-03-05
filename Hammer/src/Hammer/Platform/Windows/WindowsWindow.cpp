#include "WindowsWindow.h"
#include "Hammer/Log.h"

#include "Hammer/Events/KeyEvent.h"
#include "Hammer/Events/MouseEvent.h"
#include "Hammer/Events/ApplicationEvent.h"
#include "glad/glad.h"
namespace Hammer
{
static bool glfwInitialized = false;

Window*Window::Create(const WindowProps& props)
{
	return new WindowsWindow(props);
}

WindowsWindow::WindowsWindow(const WindowProps& props)
{
	Init(props);
}

void WindowsWindow::ShutDown()
{
	glfwDestroyWindow(m_Window);
}

WindowsWindow::~WindowsWindow()
{
	ShutDown();
}



void WindowsWindow::Init(const WindowProps& props)
{
	m_Data.title = props.Title;
	m_Data.height = props.Height;
	m_Data.width = props.Width;

	if(!glfwInitialized)
	{
	int status = glfwInit();
	if (status) HM_CORE_DEBUG("Initializing GLFW");
	else HM_CORE_CRITICAL("[ERROR] to initalize GLFW");
	}
	m_Window = glfwCreateWindow(m_Data.width, m_Data.height, m_Data.title.c_str(), nullptr, nullptr);
	if (m_Window)HM_CORE_DEBUG("Window created '{0}', ({1},{2})", m_Data.title, m_Data.width, m_Data.height);
	else HM_CORE_CRITICAL("[ERROR] to initalize GLFW");
	
	

	
	glfwMakeContextCurrent(m_Window);
	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	if (status) HM_CORE_DEBUG("Initializing Glad");
	else HM_CORE_CRITICAL("[ERROR] to initalize Glad");
	glfwSetWindowUserPointer(m_Window, &m_Data);
	SetVSync(true);

	

	glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) 
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		switch (action)
		{
		case GLFW_PRESS:
		{
			KeyPressedEvent e(key);
			data.EventCallback(e);
			break;
		}
		case GLFW_RELEASE:
		{
			KeyReleasedEvent e(key);
			data.EventCallback(e);
			break;
		}
		case GLFW_REPEAT:
		{
			KeyPressedEvent e(key);
			data.EventCallback(e);
			break;
	}
		}

	});

	glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int codepoint) 
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

	});


	

	glfwSetWindowCloseCallback(m_Window,[](GLFWwindow* window) 
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		WindowCloseEvent e;
		data.EventCallback(e);

	});


	glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int xpos, int ypos)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		WindowMovedEvent e(xpos,ypos);
		data.EventCallback(e);
	});



	glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) 
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		data.width = width;
		data.height = height;
		WindowResizeEvent e(width,height);
		data.EventCallback(e);

	});

	glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		if (focused)
		{
			WindowFocusEvent e;
			data.EventCallback(e);
		}
		else
		{
			WindowLostFocusEvent e;
			data.EventCallback(e);
		}

	});


	glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) 
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		switch (action)
		{
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent e(button);
				data.EventCallback(e);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent e(button);
				data.EventCallback(e);
				break;
			}
		}


	});

	glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset) 
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		MouseScrolledEvent e(xoffset, yoffset);
		data.EventCallback(e);
	});

	glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
	{
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		MouseMovedEvent e(xpos, ypos);
		data.EventCallback(e);

	});

	glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) 
	{
		glViewport(0, 0, width, height);
	});
}

void WindowsWindow::OnUpDate()
{
	glfwPollEvents();
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(m_Window);
}

bool WindowsWindow::IsVSync() const
{
	if (m_Data.VSync)return true;
	return false;
}

void WindowsWindow::SetVSync(bool enabled)
{
	if (enabled)
		glfwSwapInterval(1);
	else
		glfwSwapInterval(0);
	m_Data.VSync = enabled;
}



}