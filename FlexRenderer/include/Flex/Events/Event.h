#pragma once
#include <Core.h>
#include <vector>
#include <memory>

namespace Flex {
	class EventHandler;
	class Event
	{
	public:
		FLEX_API void AddHandler(const EventHandler& handler);
		FLEX_API void RemoveHandler(const EventHandler& handler);

		//Call the event and notify all the handlers
		FLEX_API void operator()();

		//Subscribe a handler to the event
		FLEX_API Event &operator+=(const EventHandler &handler);
		//Unsubscribe a handler to the event
		FLEX_API Event &operator-=(const EventHandler &handler);
	private:
		std::vector<std::shared_ptr<EventHandler>> m_handlers;

		void notifyHandlers();
	};
}

