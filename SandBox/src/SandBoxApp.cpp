#include <Hammer.h>

class SandBoxApplication:public Hammer::Application
{
public:
	SandBoxApplication()
	{

	}
	~SandBoxApplication()
	{

	}
};

Hammer::Application* Hammer::CreateApplication()
{
	return new SandBoxApplication();
}
