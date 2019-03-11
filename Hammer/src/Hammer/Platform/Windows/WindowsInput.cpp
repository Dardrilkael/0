#include "hmpch.h"
#include "WindowsInput.h"
#include "GLFW/glfw3.h"
#include "Hammer/Application.h"

namespace Hammer{
	Input* Input::s_Intance = new WindowsInput();
bool WindowsInput::IsKeyPressedImpl(int keycode) const
{
	GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
	auto state = glfwGetKey(window,keycode);
	return state == GLFW_PRESS || state ==GLFW_REPEAT;
}

bool WindowsInput::IsMouseButtonPressedImpl(int button) const
{
	GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
	auto state = glfwGetMouseButton(window, button);
	return state == GLFW_PRESS;
}

std::pair<float, float> WindowsInput::GetMousePositionImpl() const
{
	GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
	double xPos, yPos;
	glfwGetCursorPos(window, &xPos, &yPos);
	return { xPos,yPos };
}

float WindowsInput::GetMouseXPosImpl() const
{
	auto[x, y] = GetMousePositionImpl();
	return x;
}

float WindowsInput::GetMousYPosImpl() const
{
	auto[x, y] = GetMousePositionImpl();
	return y;
}

}