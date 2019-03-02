#pragma once 
//#include ""
#ifdef HM_PLATFORM_WINDOWS

extern Hammer::Application* Hammer::CreateApplication();

int main()
{
	Hammer::Application* app = Hammer::CreateApplication();
	app->Run();
	delete app;
}

#endif