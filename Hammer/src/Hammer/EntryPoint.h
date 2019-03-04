#pragma once 
#ifdef HM_PLATFORM_WINDOWS

extern Hammer::Application* Hammer::CreateApplication();


int main()
{
	Hammer::Log::Init();
	HM_CORE_TRACE("Water");
	HM_LOG_TRACE("Water");
	Hammer::Application* app = Hammer::CreateApplication();
	app->Run();
	delete app;
}

#endif