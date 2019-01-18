#include "flpch.h"
#include "Flex/Application.h"
#include <memory>
#include "Flex/Window.h"
#include "Flex/Events/ApplicationEvent.h"
#include "Flex/Log.h"

namespace Flex {

	Application::Application()
	{
		m_window = std::unique_ptr<Window>(Window::Create());
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (true)
		{
			m_window->OnUpdate();
		}
	}
} 