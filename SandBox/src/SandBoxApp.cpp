#include <Hammer.h>
#include <iostream>
class ExampleLayer: public Hammer::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{
		HM_CORE_TRACER
	}

	void OnUpdate() override
	{

		//HM_LOG_DEBUG("ExampleLayer::Update");

		

	}
	
	void OnEvent(Hammer::Event& e) override
	{
		//HM_LOG_TRACE("{0}",e);
		if (e.GetEventType() == Hammer::KeyPressedEvent::GetStaticType())
		{
			Hammer::KeyPressedEvent& evento = (Hammer::KeyPressedEvent&)e;
			HM_LOG_TRACE((char)evento.GetKeyCode());
		}

		if (e.GetEventType() == Hammer::MouseButtonPressedEvent::GetStaticType())
		{
			Hammer::MouseButtonPressedEvent& evento = (Hammer::MouseButtonPressedEvent&)e;
			switch (evento.GetMouseButton())
			{
			case 0:
				HM_LOG_TRACE("Mouse Left Button");
				break;
			case 1:
				HM_LOG_TRACE("Mouse Right Button");
				break;
			}
			
		}
	}
};

class SandBoxApplication:public Hammer::Application
{
public:
	SandBoxApplication()
	{
		HM_CORE_TRACER
		PushLayer(new ExampleLayer());
		PushOverlay(new Hammer::ImGuiLayer());

	}
	~SandBoxApplication()
	{

	}
};

Hammer::Application* Hammer::CreateApplication()
{
	return new SandBoxApplication();
}
