#pragma once
#include "Event.h"

namespace Hammer {

class HM_API MouseButtonEvent :public Event
{
protected:
	MouseButtonEvent(int button) :m_Button(button){}
	int m_Button;
public:
	int GetMouseButton() { return m_Button; }

	EVENT_CLASS_CATEGORY(EventCategoryInput|EventCategoryMouse| EventCategoryMouseButton)
};

class HM_API MouseButtonPressedEvent :public MouseButtonEvent
{
public:
	MouseButtonPressedEvent(int button) :MouseButtonEvent(button) {}

	std::string ToString() const override
	{
		std::stringstream out;
		out << GetName() << " : " << m_Button;
		return out.str();
	}
	EVENT_CLASS_TYPE(MouseButtonPressed)
};

class HM_API MouseButtonReleasedEvent :public MouseButtonEvent
{
public:
	MouseButtonReleasedEvent(int button) :MouseButtonEvent(button) {}

	std::string ToString() const override
	{
		std::stringstream out;
		out << GetName() << ": " << m_Button;
		return out.str();
	}
	EVENT_CLASS_TYPE(MouseButtonReleased)

};

class HM_API MouseScrolledEvent : public Event
{
public:
	MouseScrolledEvent(float xOffset,float yOffset) :
		m_xOffset(xOffset), m_yOffset(yOffset){}

	float GetxOffset(){ return m_xOffset; }
	float GetyOffset(){ return m_yOffset; }

	std::string ToString() const override
	{
		std::stringstream out;
		out << GetName() << ":(" <<m_xOffset<<","<<m_yOffset<<")" ;
		return out.str();
	}
	EVENT_CLASS_CATEGORY(EventCategoryMouse|EventCategoryInput)
	EVENT_CLASS_TYPE(MouseScrolled)
private:
	float m_xOffset;
	float m_yOffset;

};

class HM_API MouseMovedEvent : public Event
{
public:
	MouseMovedEvent(float xPos, float yPos) :
		m_xPos(xPos), m_yPos(yPos) {}

	float GetxPos() { return m_xPos; }
	float GetyPos() { return m_yPos; }

	std::string ToString() const override
	{
		std::stringstream out;
		out << GetName() << ":(" << m_xPos << "," << m_yPos << ")";
		return out.str();
	}
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	EVENT_CLASS_TYPE(MouseMoved)
private:
	float m_xPos;
	float m_yPos;

};


}