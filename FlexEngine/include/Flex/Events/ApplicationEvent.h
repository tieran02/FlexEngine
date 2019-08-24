#pragma once
#include "flpch.h"
#include "Flex/Core.h"
#include "IEvent.h"


namespace Flex
{
	class FLEX_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height): m_width(width), m_height(height) {}

		inline unsigned int GetWidth() const { return m_width; }
		inline unsigned int GetHeight() const { return m_height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_width << ", " << m_height;
			return ss.str();
		}

		int GetCategoryFlags() const override { return EventCategoryApplication; }

		static EventType GetStaticType() { return EventType::WindowResize; }
		EventType GetEventType() const override
		{
			return GetStaticType();
		}
		const char* GetName() const override
		{
			return "WindowResize";
		}

	protected:;
		unsigned int m_width, m_height;
	};

	class FLEX_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		std::string ToString() const override
		{
			return "WindowCloseEvent";
		}

		int GetCategoryFlags() const override { return EventCategoryApplication; }

		static EventType GetStaticType() { return EventType::WindowClose; }
		EventType GetEventType() const override
		{
			return GetStaticType();
		}
		const char* GetName() const override
		{
			return "WindowClose";
		}
	};

	class FLEX_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() = default;

		std::string ToString() const override
		{
			return "AppTickEvent";
		}

		int GetCategoryFlags() const override { return EventCategoryApplication; }

		static EventType GetStaticType() { return EventType::AppTick; }
		EventType GetEventType() const override
		{
			return GetStaticType();
		}
		const char* GetName() const override
		{
			return "AppTick";
		}
	};

	class FLEX_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() = default;

		std::string ToString() const override
		{
			return "AppUpdateEvent";
		}

		int GetCategoryFlags() const override { return EventCategoryApplication; }

		static EventType GetStaticType() { return EventType::AppUpdate; }
		EventType GetEventType() const override
		{
			return GetStaticType();
		}
		const char* GetName() const override
		{
			return "AppUpdate";
		}
	};

	class FLEX_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() = default;

		std::string ToString() const override
		{
			return "AppRenderEvent";
		}

		int GetCategoryFlags() const override { return EventCategoryApplication; }

		static EventType GetStaticType() { return EventType::AppRender; }
		EventType GetEventType() const override
		{
			return GetStaticType();
		}
		const char* GetName() const override
		{
			return "AppRender";
		}
	};
}