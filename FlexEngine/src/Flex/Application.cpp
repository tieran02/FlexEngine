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
			for (Layer* layer : m_layerStack)
			{
				layer->OnUpdate();
			}

			m_window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));

		//handle layer events in reverse
		for (auto it = m_layerStack.end(); it != m_layerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}

	}

	void Application::PushLayer(Layer* layer)
	{
		m_layerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_layerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent e)
	{
		m_running = false;
		return true;
	}
} 