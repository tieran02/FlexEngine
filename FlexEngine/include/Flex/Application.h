#pragma once
#include "Core.h"
#include <memory>

namespace Flex {
	class Window;
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
