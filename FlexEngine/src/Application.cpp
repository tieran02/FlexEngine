#include "Application.h"
#include <memory>
#include "Window.h"

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
		while (!m_window->ShouldClose())
		{
			m_window->Update();
		}
	}
} 