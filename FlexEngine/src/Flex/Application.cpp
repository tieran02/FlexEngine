#include "pchheader.h"
#include "Flex/Application.h"
#include <Platform/Vulkan/VulkanRenderer.h>
#include "Flex/IWindow.h"
#include "Flex/Events/ApplicationEvent.h"

namespace Flex {

    Application* Application::m_instance = nullptr;

	Application::Application()
	{
	    FL_ASSERT(m_instance == nullptr, "Only one instance of the application is allowed!");
	    m_instance = this;
        create();
	}


	Application::~Application()
	{

	}

	void Application::Run()
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

	void Application::PushLayer(ILayer* layer)
	{
		m_layerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(ILayer* overlay)
	{
		m_layerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent e)
	{
		m_running = false;
		return true;
	}

    void Application::create()
    {
        m_window = std::unique_ptr<IWindow>(IWindow::Create());
        m_window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

        //create renderer
        m_renderer = VulkanRenderer::Create();
    }

    Application &Application::Instance()
    {
        return *m_instance;
    }

    IWindow &Application::GetWindow()
    {
        return *m_window;
    }

    IRenderer &Application::GetRenderer()
    {
        return *m_renderer;
    }
} 