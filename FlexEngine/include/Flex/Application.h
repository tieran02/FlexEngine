#pragma once
#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace Flex {
	class Application
	{
	public:
		FLEX_API Application();
		FLEX_API virtual ~Application();
		FLEX_API void Run();

		FLEX_API void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent e);

		std::unique_ptr<Window> m_window;
		bool m_running{ true };
	};

	//TO be defined in a client
	Application* CreateApplication();
}
