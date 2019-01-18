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
		m_window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_running)
		{
			m_window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));
		FL_LOG_CORE_INFO("{0}", e);

	}

	bool Application::OnWindowClose(WindowCloseEvent e)
	{
		m_running = false;
		return true;
	}
} 