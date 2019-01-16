#pragma once
#include <functional>

namespace Flex {
	class EventHandler
	{
	public:
		using Func = std::function<void()>;

		unsigned int ID;
		unsigned static int COUNTER;

		EventHandler() : ID{0}{}

		EventHandler(const Func& func);

		//Call all the subscribed handlers
		void operator()();

		void operator=(const EventHandler &func);

		bool operator==(const EventHandler &del);
		bool operator!=(nullptr_t);
	private:
		Func m_func;
	};
}
