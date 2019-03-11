#pragma once
#include "hmpch.h"
#include "Core.h"

#include "Events/Event.h"

namespace Hammer {
	class HM_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		struct WindowProps
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;

			WindowProps(std::string title= "Hammer Window", unsigned int width= 1280, unsigned int height =720 ):Title(title),Width(width),Height(height){}
		};

		static Window* Create(const WindowProps& props = WindowProps());
		virtual void Init(const WindowProps& props) = 0;

		virtual void OnUpDate() = 0;

		virtual bool IsVSync() const = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		virtual void* GetNativeWindow() const = 0;

	};


}