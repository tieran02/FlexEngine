#pragma once
#include "Core.h"
#include <functional>

namespace Flex {
	class EventHandler
	{
	public:
		using Func = std::function<void()>;

		unsigned int ID;
		unsigned static int COUNTER;

		FLEX_API EventHandler() : ID{0}{}

		FLEX_API EventHandler(const Func& func);

		//Call all the subscribed handlers
		FLEX_API void operator()();

		FLEX_API EventHandler& operator=(const EventHandler &func);

		FLEX_API bool operator==(const EventHandler &del);
		FLEX_API bool operator!=(nullptr_t);
	private:
		Func m_func;
	};
}
