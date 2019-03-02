#pragma once
#include "Core.h"

namespace Hammer 
{
	class HM_API Application
	{
		bool m_Running = true;
	
	public:
		Application();
		~Application();
		void Run();
	};
	Application* CreateApplication();
}
