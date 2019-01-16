#pragma once
#include <vector>
#include <memory>

namespace  Flex {
	class EventHandler;
	class Event
	{
	public:
		void AddHandler(const EventHandler& handler);
		void RemoveHandler(const EventHandler& handler);

		//Call the event and notify all the handlers
		void operator()();

		//Subscribe a handler to the event
		Event &operator+=(const EventHandler &handler);
		//Unsubscribe a handler to the event
		Event &operator-=(const EventHandler &handler);
	private:
		std::vector<std::unique_ptr<EventHandler>> m_handlers;

		void notifyHandlers();
	};
}

