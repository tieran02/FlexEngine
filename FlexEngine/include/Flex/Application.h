#pragma once
#include "Core.h"
#include "Window.h"
#include "Events/Event.h"

namespace Flex {
	class Application
	{
	public:
		FLEX_API Application();
		FLEX_API virtual ~Application();
		FLEX_API void Run();
	private:
		std::unique_ptr<Window> m_window;
	};

	//TO be defined in a client
	Application* CreateApplication();
}
