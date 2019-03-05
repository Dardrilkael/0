#pragma once 
#ifdef HM_PLATFORM_WINDOWS

extern Hammer::Application* Hammer::CreateApplication();


int main()
{
	Hammer::Log::Init();
	Hammer::Application* app = Hammer::CreateApplication();
	app->Run();
	delete app;
}

#endif