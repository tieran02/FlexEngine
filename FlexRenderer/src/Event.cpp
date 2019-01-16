#include "Event.h"
#include "EventHandler.h"

namespace  Flex {
	void Event::AddHandler(const EventHandler& handler)
	{
		m_handlers.push_back(std::unique_ptr<EventHandler>(new EventHandler{ handler }));
	}

	void Event::RemoveHandler(const EventHandler& handler)
	{
		for (int i = 0; i < m_handlers.size(); ++i)
		{
			if (*m_handlers[i] == handler)
			{
				m_handlers.erase(m_handlers.begin() + i);
				return;
			}
		}
	}

	void Event::operator()()
	{
		notifyHandlers();
	}

	Event& Event::operator+=(const EventHandler& handler)
	{
		AddHandler(handler);
		return *this;
	}

	Event& Event::operator-=(const EventHandler& handler)
	{
		RemoveHandler(handler);
		return *this;
	}

	void Event::notifyHandlers()
	{
		for (auto& handler : m_handlers)
		{
			if (*handler != nullptr && handler->ID != 0)
				(*handler)();
		}
	}
}
