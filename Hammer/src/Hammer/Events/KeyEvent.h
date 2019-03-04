#include "Event.h"

namespace Hammer{

class HM_API KeyEvent :public Event
{public:
	
	int GetKey() { return m_KeyCode; }
	EVENT_CLASS_CATEGORY(EventCategoryKeyboard| EventCategoryInput)
protected:
	KeyEvent(int keycode):m_KeyCode(keycode){}
	int m_KeyCode;

};

class HM_API KeyPressedEvent :public KeyEvent
{
public:
	KeyPressedEvent(int keycode):
	KeyEvent(keycode){}

	std::string ToString() const override
	{
		std::stringstream out;
		out << "KeyPressed: " << (char)m_KeyCode<<"("<<m_KeyCode<<")";
		return out.str();
	}


	EVENT_CLASS_TYPE(KeyPressed)
};

class HM_API KeyReleasedEvent :public KeyEvent
{
public:
	KeyReleasedEvent(int keycode) :
		KeyEvent(keycode) {}

	std::string ToString() const override
	{
		std::stringstream out;
		out << GetName() << ": " << (char)m_KeyCode << "(" << m_KeyCode << ")";
		return out.str();
	}

	EVENT_CLASS_TYPE(KeyReleased)

};

}