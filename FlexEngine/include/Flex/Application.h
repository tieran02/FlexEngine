#pragma once

#include <Flex/Rendering/IRenderer.h>
#include "Core.h"
#include "IWindow.h"
#include "Flex/Events/IEvent.h"
#include "Events/ApplicationEvent.h"
#include "LayerStack.h"

namespace Flex {
	class Application
	{
	public:
		FLEX_API Application();
		FLEX_API virtual ~Application();
		FLEX_API void Run();

		FLEX_API void OnEvent(Event& e);

		FLEX_API void PushLayer(ILayer* layer);
		FLEX_API void PushOverlay(ILayer* overlay);

        FLEX_API static Application& Instance();

        FLEX_API IWindow& GetWindow();
        FLEX_API IRenderer& GetRenderer();
	private:
	    static Application* m_instance;

		bool OnWindowClose(WindowCloseEvent e);

		std::unique_ptr<IWindow> m_window;
        std::unique_ptr<IRenderer> m_renderer;
		bool m_running{ true };
		LayerStack m_layerStack;

		void create();
	};

	//TO be defined in a client
	Application* CreateApplication();
}
