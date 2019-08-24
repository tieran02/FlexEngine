#include "flpch.h"
#include "Flex/IApplication.h"
#include <memory>
#include "Flex/IWindow.h"
#include "Flex/Events/ApplicationEvent.h"
#include "Flex/Log.h"

namespace Flex {

	IApplication::IApplication()
	{
		m_window = std::unique_ptr<IWindow>(IWindow::Create());
		m_window->SetEventCallback(std::bind(&IApplication::OnEvent, this, std::placeholders::_1));
	}


	IApplication::~IApplication()
	{

	}

	void IApplication::Run()
	{
		while (m_running)
		{
			for (ILayer* layer : m_layerStack)
			{
				layer->OnUpdate();
			}

			m_window->OnUpdate();
		}
	}

	void IApplication::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&IApplication::OnWindowClose, this, std::placeholders::_1));

		//handle layer events in reverse
		for (auto it = m_layerStack.end(); it != m_layerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}

	}

	void IApplication::PushLayer(ILayer* layer)
	{
		m_layerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void IApplication::PushOverlay(ILayer* overlay)
	{
		m_layerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	bool IApplication::OnWindowClose(WindowCloseEvent e)
	{
		m_running = false;
		return true;
	}
} 