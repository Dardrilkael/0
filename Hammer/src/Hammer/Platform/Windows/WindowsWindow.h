#pragma once
#include "Hammer/Window.h"
#include "GLFW/glfw3.h"

namespace Hammer {

class WindowsWindow :public Window
{
public:
	WindowsWindow(const WindowProps& props);
	~WindowsWindow();

	
	virtual void Init(const WindowProps& props) override ;
	virtual void OnUpDate() override ;
	virtual bool IsVSync() const override ;
	virtual void SetVSync(bool enabled) override ;
	inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
	void ShutDown();

	virtual unsigned int GetWidth() const { return m_Data.width; }
	virtual unsigned int GetHeight() const { return m_Data.height; }

private:
	
	struct WindowData
	{
		std::string title;
		unsigned int width;
		unsigned int height;
		bool VSync;
		EventCallbackFn EventCallback;
	};
	GLFWwindow* m_Window;
	WindowData m_Data;


	// Herdado por meio de Window
	virtual inline void * GetNativeWindow() const override {return m_Window;}

};


}
