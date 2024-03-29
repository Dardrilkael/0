#pragma once
#include "Event.h"

namespace Hammer {


	class HM_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) :
			m_Width(width), m_Height(height) {}
		inline unsigned int GetWidth() { return m_Width; }
		inline unsigned int GetHeight() { return m_Height; }

		EVENT_CLASS_TYPE(WindowResized)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)

		virtual std::string ToString() const override
		{
			std::stringstream out;
			out << GetName() << ":(" << m_Width <<", "<< m_Height << ")";
			return out.str();
		}

	private:
		unsigned int m_Width, m_Height;
	};



	class HM_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HM_API WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent() {}

		EVENT_CLASS_TYPE(WindowFocus)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HM_API WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent() {}

		EVENT_CLASS_TYPE(WindowLostFocus)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HM_API WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(int xPos,int yPos):m_xPos(xPos),m_yPos(yPos) {}

		inline int GetXPos(){return m_xPos;}
		inline int GetYPos(){return m_yPos;}


		virtual std::string ToString() const override
		{
			std::stringstream out;
			out << GetName() << ": (" << m_xPos << ", " << m_yPos << ")";
			return out.str();

		}
		EVENT_CLASS_TYPE(WindowMoved)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)


	private:
		int m_xPos, m_yPos;
	};

	class HM_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HM_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HM_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

}