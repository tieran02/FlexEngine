#include "EventHandler.h"
#include "Log.h"

namespace Flex
{
	unsigned int EventHandler::COUNTER = 0;

	EventHandler::EventHandler(const Func& func) : m_func{ func }
	{
		ID = ++COUNTER;
	}

	void EventHandler::operator()()
	{
		m_func();
	}

	void EventHandler::operator=(const EventHandler& func)
	{
		if (m_func == nullptr) {
			m_func = func;
			ID = ++COUNTER;
		}
		else 
		{
			FL_LOG_ERROR("Tried assigning an existing EventHandler to a new EventHandler");
		}
	}

	bool EventHandler::operator==(const EventHandler& del)
	{
		return ID == del.ID;
	}

	bool EventHandler::operator!=(nullptr_t)
	{
		return m_func != nullptr;
	}
}
